package copool

import (
	"log"
	"sync"
)

var(
	companies =make(map[string]*company)
	globalLocker = &sync.Mutex{}
)



type task struct {
	_task func()interface{}
	_tasks *tasks
}

func (t *task)done()  {
	t._tasks.locker.Lock()
	defer t._tasks.locker.Unlock()
	t._tasks.finishCount+=1
	if t._tasks.finishCount== len(t._tasks._tasks){
		close(t._tasks.truck)
	}
}

type tasks struct{
	_tasks []*task
	finishCount int
	locker *sync.Mutex
	truck chan interface{}
}

/**
Wait until all the tasks has been finished and return them
 */
func (t *tasks)GetAll()[]interface{}{
	products := make([]interface{},0,len(t._tasks))
	for product := range t.truck{
		products = append(products,product)
	}
	return products
}

/**

Init the coroutine pool used for AfterSale Refund

params:
	bufSize: Buffer size of channel
    workNum: The number of worker
 */
func StartUp(companyName string, bufSize,workerNum int){
	comp := &company{
		workers: make([]*worker,0,workerNum),
		pipeline: make(chan *task,bufSize),
		name: companyName,
	}

	for i :=0;i<workerNum;i++{
		comp.workers = append(comp.workers,&worker{id: i,company: comp})
	}

	companies[companyName] = comp
	comp.run()
}

// Get the company
func GetCompany(companyName string)*company{
	if c,exist := companies[companyName];exist{
		return c
	}
	return nil
}

// Company
type company struct{
	workers []*worker
	pipeline chan *task
	name string
}

// Push the task to the company
func (c *company)Push(allTasks []func()interface{})*tasks{
	_ts := &tasks{
		_tasks:      make([]*task,0,len(allTasks)),
		finishCount: 0,
		locker:      &sync.Mutex{},
		truck:       make(chan interface{}),
	}
	for _,t := range allTasks{
		_task := &task{
			_task:  t,
			_tasks: _ts,
		}
		c.pipeline <- _task
		_ts._tasks = append(_ts._tasks,_task)
	}
	return _ts
}

// Force all the workers to work
func (c *company)run(){
	for _, w := range c.workers{
		go w.hardWork(c.pipeline)
	}
}

func (c *company)hire(id int){
	w := &worker{id: id,company: c}
	c.workers = append(c.workers,w)
	w.hardWork(c.pipeline)
}

// Close the company and all the workers go home
func (c *company)Bankrupt(){
	globalLocker.Lock()
	defer globalLocker.Unlock()
	close(c.pipeline)
	delete(companies,c.name)
}


// Worker
type worker struct{
	id int
	company *company
}

// Work
func (w *worker)hardWork(pipeline chan *task){
	defer func() {
		if err:=recover();err!=nil{
			log.Printf("Worker %d has died. %s hires another one",w.id,w.company.name)
			w.company.hire(w.id)
		}
	}()
	for task := range pipeline{
		// imitate RAII
		func() {
			defer task.done()
			res := task._task()
			task._tasks.truck <- res
		}()
	}
}