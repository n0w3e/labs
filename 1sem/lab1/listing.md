```
stepn@DESKTOP-OJ14QF7 MINGW64 ~/github (master)
$ git init
Reinitialized existing Git repository in C:/Users/stepn/github/.git/

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github (master)
$ git clone https://github.com/n0w3e/labs.git
Cloning into 'labs'...
remote: Enumerating objects: 32, done.
remote: Counting objects: 100% (32/32), done.
remote: Compressing objects: 100% (20/20), done.
remote: Total 32 (delta 0), reused 24 (delta 0), pack-reused 0
Receiving objects: 100% (32/32), 4.94 KiB | 101.00 KiB/s, done.

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github (master)
$ cd labs/

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ mkdir lab1

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ cd lab1/

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs/lab1 (main)
$ touch listing.md

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs/lab1 (main)
$ touch report.md

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ git add lab1/

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ git status
On branch main
Your branch is up to date with 'origin/main'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   lab1/listing.md
        new file:   lab1/report.md

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ git commit -m 'new files'
[main b46d77a] new files
 2 files changed, 55 insertions(+)
 create mode 100644 lab1/listing.md
 create mode 100644 lab1/report.md

stepn@DESKTOP-OJ14QF7 MINGW64 ~/github/labs (main)
$ git push origin
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (5/5), 1.61 KiB | 1.61 MiB/s, done.
Total 5 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/n0w3e/labs.git
   1ae6610..b46d77a  main -> main
```
