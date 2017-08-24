# Shinda
This is a small library for work with Github repositories. Shinda will help you with your dependencies(Github only) and that's very conveniently.

All you need to do is 
* Clone shindakioku/shinda
* Add your dependencies to shinda.json

After that, you only need to run Shinda. The library will take all the work on itself

Q: Okay, how can I build 'Shinda'?
A: That's easy. You can use cmake or compiler with gcc

---
#### Cmake
```
 git clone https://github.com/shindakioku/shinda
 cd shinda
 cmake .
 make
```

#### G++
(You need to have a curl)

```
git clone https://github.com/shindakioku/shinda
cd shinda
g++ -std=c++11 main.cpp github/Github.cpp reader/Json.cpp reader/Reader.cpp core/Checker.cpp core/Core.cpp core/FileSystem.cpp -o shinda -lcurl
```

That's all. After build, you can run Shinda as follows ``` ./shinda ```

---
#### Something from me.
If you added dependency to shinda.json and this dependency also have shinda.json (shinda/shinda.json), Shinda will detect it and download all packages.

---
You can see shinda.json after clone this repository. It's for you, you can test how ```shinda`` is working.