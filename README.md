# List


A better version of 'ls'

- better tree representation

- icons

![alt text](./screenshots/image.png)

Version 2

### Requirements

- Nerdfont https://www.nerdfonts.com/font-downloads

### TODO

- themes (only default is available now)

### Minor bugs

- size align breaks with large names

### Install

#### Linux

```sh
cd <this folder>
sh ./install.sh
```

### Usage
``` bash
list <'path'> <'-flags'>
```

#### Flags

- ```R``` recursive 
- ```d``` file size
- ```a``` hidden files
- ```V``` version
- ```l``` permissions

### ls vs list

- list takes about 2x ram
- speed is really close to ls, difference could be measured in ms or less
