#include <string.h>
#include "llist.h"

// helper function to check credentials
// should work for shallow and deep copying of usernames and passwords
// will not work for very deep copying of next
//   which one shouldn't do anyways, because:
//     that would result in list construction taking O(n^2) time (should be
//     O(n)) ensuring everything is freed would be a COLOSSAL pain
//   (also, I doubt anyone would even think to do that)
void ceq(struct Cred* cred, int i, char* name, char* pass, struct Cred* next) {
  if (!cred) {
    printf("cred%i is NULL (shouldn't be) INCORRECT\n", i);
    return;
  }

  printf("cred%i fields:\n", i);
  printf("  username is \"%s\" (should be \"%s\") %s\n", get_username(cred),
         name, strcmp(get_username(cred), name) ? "INCORRECT" : "ok");
  printf("  password is \"%s\" (should be \"%s\") %s\n", get_password(cred),
         pass, strcmp(get_password(cred), pass) ? "INCORRECT" : "ok");
  printf("  address of next is %p (should be %p) %s\n", get_next(cred), next,
         get_next(cred) == next ? "ok" : "INCORRECT");
}

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  char name[] = "user1";  // doing this to check something later on
  char pass[] = "pass1";  // doing this to check something later on
  struct Cred* cred1 = cred(name, pass, NULL);
  ceq(cred1, 1, "user1", "pass1", NULL);

  printf("\n");
  if (get_username(cred1) == name) {
    printf("It would appear you are using a shallow copy of the username.\n");
    printf("For this challenge, this is completely fine.\n");
    printf(
        "But make sure you understand why it is that if name[] were "
        "altered,\n");
    printf("  cred1's name field would also be altered.\n");
    printf(
        "So in a lot of cases, you'll find you actually want to store a "
        "copy.\n");
    printf(
        "  (which can be made via strdup(), but will then need to be "
        "freed.)\n");
  } else {
    printf("It would appear you are using a deeper copy of the username.\n");
    printf("Make sure that if you free the space that copy was put in.\n");
    printf("Naturally, you'll need to free them within cred_free().\n");
    printf(
        "But you'll need free the old names/passwords in the setters as "
        "well.\n");
  }

  struct Cred* cred2 = cred("user2", "pass2", NULL);
  printf("\n");
  ceq(cred2, 2, "user2", "pass2", NULL);

  struct Cred* cred3 = cred("user3", "pass3", cred1);
  printf("\n");
  ceq(cred3, 3, "user3", "pass3", cred1);

  set_username(cred3, "super_user");
  set_password(cred3, "pass123");
  set_next(cred3, cred2);
  printf("\n");
  ceq(cred3, 3, "super_user", "pass123", cred2);

  // We've added -fsanitize=address to compilation in order to show if a memory
  // leak occurs
  cred_free(cred1);  // should free cred1
  cred_free(cred3);  // should free cred3 and cred2
}
