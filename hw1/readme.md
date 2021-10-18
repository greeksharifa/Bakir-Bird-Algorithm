## Homework 1

### Checker Program

naive한 방법으로 구현되어 있습니다. 첫번째 row/col에서부터 시작하여 마지막까지 sliding하며 주어진 pattern이 text 중에서 match되는 부분이 있는지를 check합니다.

효율적이지는 않은 구현 방법이지만, 최대 입력 크기가 크지 않은 만큼 최악의 경우(O(n^4))에도 빠른 시간 안에 수행됩니다.

---

### Environments

- Ubuntu 18.04
- compile option: `g++ -o -O3 `

---

### Makefile

- compile: `make all`
- delete executable: `make clean`

---

### Run
- run: `./BakerBird bb_in.txt bb_out.txt`
- checker: `./checker bb_in.txt bb_out.txt cc_out.txt`

---
### Experiments

**input 1**: 

```
4 12
Aaa0
bBbb
ccCc
0ddD
aabAaa0123ba
aaabBbbabb90
11bccCcZZaba
AXA0ddDaabba
AAabbaaabb01
Aaa0Aaa0Aaa0
bBBbBbBbbBbb
cCZzCZcZccCc
0ddD0ddD0ddD
Z9cv8vmZ82nz
ajksjsjs9sss
9xv87bvc7vbn
```

**output 1**:
```
3 6
8 11
```

---


**input 2**:

```
6 10
azAZ09
azAZ09
azAZ09
azAZ09
azAZ09
azAZ09
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
AZazAZ09az
```

**output 2**:
```
5 7
6 7
7 7
8 7
9 7
```
