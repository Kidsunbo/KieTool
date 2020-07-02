# CoroutinePool

> This is a coroutine poll for golang.

## Usage

```go
import "copool"

copool.StartUp("kie",10,10)
fs := make([]func()interface{},0,10)
//Do work with some panic things happen
for i:=0;i<10;i++{
        c := i
        f := func()interface {}{
            fmt.Println("Start: ",c)
            time.Sleep(time.Duration(c)*time.Second)
            if c%2==0{
                panic("hey")
            }
            fmt.Println("End: ",c)
            return c
        }
        fs = append(fs,f)
    }
tasks :=copool.GetCompany("kie").Push(fs)
result :=tasks.GetAll()
```

## Notification

All the worker can recover once from panic and die after that. A new worker will be hired and start working right now.
