## Linux Kernel Module for 384 bytes Allocation Efficiency

### Description
본 프로젝트는 `5.14.214 LTS` 리눅스 커널을 기반으로 기존의 `Slab` 메모리 할당자 수정을 통해 `384 bytes` 크기의 메모리 할당 효율성을 개선한 프로젝트를 테스트하기 위한 커널 모듈입니다.

커널 수정 프로젝트는 다음 레포에서 확인하실 수 있습니다.<br/>
[LSA_TeamProject Repository](https://github.com/yymin1022/LSA_TeamProject/)

### How To

```bash
yong@ubuntu-server :~/Projects $ git clone https://github.com/yymin1022/LSA_kmalloc_384_test/ Modules
yong@ubuntu-server :~/Projects $ cd Modules
yong@ubuntu-server :~/Projects $ make
```
