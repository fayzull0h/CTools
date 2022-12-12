#include <stdio.h>
#include <string.h>

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

void Draw(struct fnode root) {
  if (root.father != NULL) {
    printf("\t");
    Draw(*root.father);
    printf("\v\b\b\b\b\b\b\b\b%s", root.name);
  } else
    printf("%s", root.name);
  if (root.mother != NULL) {
    printf("\v\\\v");
    Draw(*root.mother);
  } else
    printf("\n\t\b/");
}

void draw(struct fnode root) {
  int c = strlen(root.name);
  if (root.father != NULL) {
    // "Tab" forward
    for (int i = -3; i < c; i++)
      printf(" ");

    draw(*root.father);
    printf("|\v");
    for (int i = -3; i < c; i++)
      printf("\b");

    printf(">--%s", root.name);
  } else {
    printf(">--%s\v", root.name);
    for (int i = -3; i < c; i++)
      printf("\b");
  }
}



int main(int argc, char * argv[]) {
  // Father's Side
  struct fnode Rahbarhon = {"Rahbarhon", NULL, NULL};
  struct fnode Adham = {"Adham", NULL, NULL};
  struct fnode Rozahon = {"Rozahon", NULL, &Rahbarhon};
  struct fnode Farhod = {"Farhod", &Adham, &Rozahon};

  // Mom's Side
  struct fnode Tolqun = {"Tolqun", NULL, NULL};
  struct fnode Hayathon = {"Hayathon", NULL, NULL};
  struct fnode Dilrabo = {"Dilrabo", &Tolqun, &Hayathon};

  // Me
  struct fnode Fayzulloh = {"Fayzulloh", &Farhod, &Dilrabo};

  // Bahar's Parents
  struct fnode Arash = {"Arash", NULL, NULL};
  struct fnode Bita = {"Bita", NULL, NULL};

  // Bahar
  struct fnode Bahar = {"Bahar", &Arash, &Bita};

  // Our child
  struct fnode child = {"child", &Fayzulloh, &Bahar};

  //printf("\t\v%s\b1\n", findSubtree(child, "Bita").name); 
  draw(Fayzulloh);
  return 0;
}
