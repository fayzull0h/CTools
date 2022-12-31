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

struct info draw(struct fnode root, int row, int col);
void drawFather(struct fnode root);
void drawMother(struct fnode root);

void drawMother(struct fnode root) {
  int c = strlen(root.name);
  int row, col;
  getyx(stdscr, row, col);

  row += 2;
  col -= 1;

  if (root.father != NULL) {
    draw(*root.father, row, col + c + 2);
    row += 2;
  } 
    
  mvprintw(row, col, ">--%s", root.name);
  
  if (root.mother != NULL) {
    draw(*root.mother, row + 2, col + c + 2);
  }
}

void drawFather(struct fnode root) {
  int c = strlen(root.name);
  int row, col;
  getyx(stdscr, row, col);
  
  if (root.father != NULL) {
    draw(*root.father, row, col);
  }

  printw(">--%s", root.name);

  getyx(stdscr, row, col);

  if (root.mother != NULL) {
    draw(*root.mother, row + 2, col - 1);
  }
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

struct info testFunc(struct info thing) {
  struct info result = {thing.fathers + 1, thing.mothers + 2};
  return result;
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

  // Bita's Family
  struct fnode Behjat = {"Behjat", NULL, NULL};
  struct fnode Mahmoud = {"Mahmoud", NULL, NULL};

  // Arash's Family
  struct fnode Yahya = {"Yahya", NULL, NULL};
  struct fnode Maryam = {"Maryam", NULL, NULL};
  struct fnode Mohammed = {"Mohammed", NULL, NULL};
  struct fnode Soghrah = {"Soghrah", NULL, NULL};
  struct fnode Mehdi = {"Mehdi", &Mohammed, &Soghrah};
  struct fnode Forough = {"Forough", &Yahya, &Maryam};

  // Bahar's Familiy
  struct fnode Arash = {"Arash", &Mehdi, &Forough};
  struct fnode Bita = {"Bita", &Mahmoud, &Behjat};
  struct fnode Bahar = {"Bahar", &Arash, &Bita};

  // Our child
  struct fnode Aisha = {"Aisha", &Fayzulloh, NULL};

  struct info test = {1, 2, 3};
  struct info t2 = testFunc(test);
  test = t2;
  test.mothers = test.mothers + 1;

  // Start NCURSES part
  initscr();
  noecho();
  
  draw(Aisha, 0, 0);
  //printw("%d, %d", t2.fathers, t2.mothers);
  //printw("%d, %d", test.fathers, test.mothers);
  refresh();
  getch();
  
  endwin();

  return 0;
}
