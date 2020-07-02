# DB2ES

> The little program that keep elastic search be consistent with database.


## Introduction
When I developed one project, some bugs always appeared oddly. After times of appearing, I found that it was due to some
data was lost in ES while database had the latest version of data. I developed a Python script to solve it, and it was great.

Now I rewrite the whole thing in C++ and wrap it to a REST API service. Here we are.

## Usage

I will create a website, and all the direction would be there if everything goes as I planed.

## Third Libraries

| Name | URL | Form | Description |
|:-----:|------| ------| ---------|
|elasticlient |https://github.com/seznam/elasticlient| Source| |
|spdlog| https://github.com/gabime/spdlog| Source| |
|thrift| http://thrift.apache.org/| Binary| This project works as a service, which needs rpc to invoke|
|mysql-connector-cpp| https://github.com/mysql/mysql-connector-cpp| Binary| |


