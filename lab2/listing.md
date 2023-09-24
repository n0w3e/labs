```

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ who

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ pwd
/c/Users/stepn/github/labs

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ ls
lab1/

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ cd lab1/

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ cp listing.md listing1.md

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ rm listing1.md

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ mv listing.md listing

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ mv listing listing.md

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ nano test.txt

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ cat test.txt
123


stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ ps
      PID    PPID    PGID     WINPID   TTY         UID    STIME COMMAND
     1976       1    1976      18112  ?         197609 21:31:28 /usr/bin/mintty
     1977    1976    1977      23344  pty1      197609 21:31:28 /usr/bin/bash
     2117    1977    2117      17900  pty1      197609 21:40:18 /usr/bin/ps

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ tail test.txt
123

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ head test.txt test2.txt
==> test.txt <==
123

==> test2.txt <==
321

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ history
  335  mkdir lab1
  336  cd lab1/
  337  touch listing.md
  338  touch report.md
  339  cd ../
  340  cd ../
  341  git checkout -b lab_1
  342  ls
  343  cd labs/
  344  ls
  459  git push origin
  460  git push origin main
  461  cd yandexhandbook/
  462  touch 1.py
  463  git add 1.py
  464  git commit 'testing file'
  465  ls
  524  mv 1.txt test.txt
  525  ls
  526  tail test.txt
  527  head test.txt
  528  touch test2.txt
  529  rm test2.txt
  530  nano test2.txt
  531  ls
  532  head test.txt test2.txt
  533  history

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ cd ../

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ mkdir folder1

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ rmdir folder1

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs (main)
$ cd lab1/

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ sudo touch pas.txt

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ echo "Hello"
Hello

stepn@DESKTOP-N0WEE MINGW64 ~/github/labs/lab1 (main)
$ ssh 185.5.249.140 -l n_stepanov
The authenticity of host '185.5.249.140 (185.5.249.140)' can't be established.
ED25519 key fingerprint is SHA256:gMWpghci4jH+8KckY83J+zLNE4DrwfrDZorZZU2IRGI.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? y
Please type 'yes', 'no' or the fingerprint: yes
Warning: Permanently added '185.5.249.140' (ED25519) to the list of known hosts.
n_stepanov@185.5.249.140's password:
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 18 10:24:25 2023 from 31.173.86.251
n_stepanov@vds2476450:~$ ssh-keygen
Generating public/private rsa key pair.
Enter file in which to save the key (/home/n_stepanov/.ssh/id_rsa): id_rsa
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in id_rsa
Your public key has been saved in id_rsa.pub

n_stepanov@vds2476450:~$ ssh-copy-id -i id_rsa.pub n_stepanov@185.5.249.140
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
n_stepanov@185.5.249.140's password:

Number of key(s) added: 1

n_stepanov@vds2476450:~$ scp -i id_rsa test.txt n_stepanov@185.5.249.140:C:\Users\stepn\github\labs\lab1
test.txt                                                        100%    0     0.0KB/s   00:00


```