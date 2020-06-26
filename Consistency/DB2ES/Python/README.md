# KieTool_DB2ES

> The little program that keep elastic search be consistent with database.


## Introduction
When I developed one project, some bugs always appeared oddly. After times of appearing, I found that it was due to some
data was lost in ES while database had the latest version of data. I developed a Python script to solve it, and this is it.

## Usage

For now, this script is used locally. Be sure that Python3 is installed, type the following commands to setup:
```commandline
pip install -r requirement.txt
```
Then change the parameters in the `setting.yml` and run the script.

I will consider to make it as a REST API like CPP version. Coming soon.

## Third Libraries

See `requirement.txt`

