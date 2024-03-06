# List

### Desc

Inspired by 'ls' unix command

Provides a better tree representation

### Requirements

- Nerdfont https://www.nerdfonts.com/font-downloads

### Bug

Aligning text is not for me

### Install

Add the following line to ~/.bashrc

```sh
alias [name]="<path to list executable>"
```
run
```sh
source ~/.bashrc
```

### Usage

compile
```
cd <this folder>
make
```

run
```
./list <path> <flags separated by space>
```

#### Flags

- ```-d``` displays file size
- ```-R``` recursive
