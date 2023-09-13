```evgenijstepanov@MacBook-Air-Evgenij ~ % git init
Reinitialized existing Git repository in /Users/evgenijstepanov/.git/
evgenijstepanov@MacBook-Air-Evgenij ~ % ls
Applications    Documents       Library         Music           Public          labs            main.cpp
Desktop         Downloads       Movies          Pictures        PycharmProjects listing.md
evgenijstepanov@MacBook-Air-Evgenij ~ % cd labs 
evgenijstepanov@MacBook-Air-Evgenij labs % git branch
  lab_1
* main
evgenijstepanov@MacBook-Air-Evgenij labs % git branch lab_1
fatal: a branch named 'lab_1' already exists
evgenijstepanov@MacBook-Air-Evgenij labs % git checkout lab_1
D       README.md
Switched to branch 'lab_1'
evgenijstepanov@MacBook-Air-Evgenij labs % ls      
listing.md      report.md
evgenijstepanov@MacBook-Air-Evgenij labs % git add .
```