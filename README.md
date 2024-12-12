# ADS SP24 Group3 Project6

This is the repository of ADS project6. The structure would be like the following:

```
ADS-Project6
├── docs 
│   ├── report.pdf
│   ├── interface.md
│   └── ...
├── src  
│   ├── code
│   │   └──  code // util.hpp main.cpp solution.hpp testcase_gen.c
│   ├── testcase
│   │   └── all used testcases
│   └── ...
└── README.md
```

### How to run?

If you wanna run the code:

- Compile all the xpp file together by running:
```bash
g++ solution.hpp tetremino.hpp util.hpp main.cpp -o -std=c++11 strip // For bonus, if you wanna use rectangles, the program need to be changed a little, all needed functions are included
./strip
```

### Testcase

All testcases are stored in the folder /testcase, use file stream to input them. 
### Attention

For anyone wanna purchase a commit, follow the rules:

- Make your commit comments clear.
- Do not purchase any meaningless commit.
- Please code in your own fork and send merge request when finished. All code sended to main branch should be reviewed detailedly.
