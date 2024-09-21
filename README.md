## Linux Kernel Module for 384 bytes Allocation Efficiency

### Description
본 프로젝트는 `5.14.214 LTS` 리눅스 커널을 기반으로 기존의 `Slab` 메모리 할당자 수정을 통해 `384 bytes` 크기의 메모리 할당 효율성을 개선한 프로젝트를 테스트하기 위한 커널 모듈입니다.

커널 모듈 로딩 시, `384 bytes` 크기의 `kmalloc` 할당 요청을 409600회 실행하며, 모듈 제거 시 할당을 해제합니다.<br/>
실행 시 요청된 총 메모리의 크기는 `dmesg`에서 확인할 수 있습니다.

커널 수정 프로젝트와 테스트 결과는 다음 레포에서 확인하실 수 있습니다.<br/>
[LSA_TeamProject Repository](https://github.com/yymin1022/LSA_TeamProject/)

### How To

1. Clone & Compile
```bash
yong@ubuntu-server :~/Projects $ git clone https://github.com/yymin1022/LSA_kmalloc_384_test/ Modules
yong@ubuntu-server :~/Projects $ cd Modules
yong@ubuntu-server :~/Projects $ make
```

2. Install & Test
```bash
yong@ubuntu-server :~/Projects $ sudo insmod kmalloc_384_test.ko
yong@ubuntu-server :~/Projects $ sudo rmmod kmalloc_384_test
yong@ubuntu-server :~/Projects $ sudo dmesg
```
