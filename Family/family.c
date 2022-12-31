#include <stdio.h>
#include <ncurses.h>
#include <string.h>

struct info {
  int name;
  int fathers;
  int mothers;
};

struct fnode {
  char name[30];
  struct fnode* father;
  struct fnode* mother;
};

struct fnode findSubtree(struct fnode target, char name[30]) {
  if (strcmp(name, target.name) == 0) {
    return target;
  } else {
    if (target.father != NULL) {
      struct fnode father = findSubtree(*target.father, name);
      if (strcmp(father.name, name) == 0)
        return father;
    } 
    if (target.mother != NULL) {
      struct fnode mother = findSubtree(*target.mother, name);
      if (strcmp(mother.name, name) == 0)
        return mother;
    }
  }
  struct fnode failed = {"", NULL, NULL};
  return failed;
}

struct info draw(struct fnode root, int row, int col) {
  int c = strlen(root.name);
  struct info parents = {c, 0, 0};
 
  move(row, col);
  if (root.father != NULL) {
    struct info temp = draw(*root.father, getcury(stdscr), getcurx(stdscr) + 2 + c);
    move(getcury(stdscr) + 2 * (temp.mothers + 1), getcurx(stdscr) - (temp.name + 2) - (c + 3));
    parents.fathers = temp.fathers + temp.mothers + 1;
  }
  
  if (root.mother != NULL) {
    struct info temp = draw(*root.mother, getcury(stdscr) + 2, getcurx(stdscr) + c + 2);
    move(getcury(stdscr) - 2 * (temp.fathers + 1), getcurx(stdscr) - (temp.name + 2) - (c + 3));
    parents.mothers = temp.mothers + temp.fathers + 1;
  }
  
  printw(">--%s", root.name);
  return parents;
}

int main() {
  // Father's Side
  struct fnode Mukarram = {"Mukarram", NULL, NULL};
  struct fnode Gulzoda = {"Gulzoda", NULL, &Mukarram};
  struct fnode Rahmat = {"Rahmat", NULL, &Gulzoda};
  struct fnode Rahbarhon = {"Rahbarhon", NULL, NULL};
  struct fnode Adham = {"Adham", NULL, NULL};
  struct fnode Rozahon = {"Rozahon", NULL, &Rahbarhon};
  struct fnode Farhod = {"Farhod", &Adham, &Rozahon};

  // Mom's Side
  struct fnode Surmahon = {"Surmahon", NULL, NULL};
  struct fnode Tolqun = {"Tolqun", NULL, &Mukarram};
  struct fnode Hayathon = {"Hayathon", NULL, &Surmahon};
  struct fnode Dilrabo = {"Dilrabo", &Tolqun, &Hayathon};

  // Me
  struct fnode Fayzulloh = {"Fayzulloh", &Farhod, &Dilrabo};

  // Start NCURSES part
  initscr();
  noecho();
  
  draw(Fayzulloh, 0, 0);

  refresh();
  getch();
  
  endwin();

  return 0;
}
