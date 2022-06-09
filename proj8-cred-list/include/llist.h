#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LLIST_H
#define LLIST_H

// Struct representing credential
// TODO: complete the struct
struct Cred {
  char* username;
  char* password;
  struct Cred* next; 
};

// goal: creates a Cred struct given the username, password, and next credential
// param username: char* representing the username
// param password: char* representing the password
// param next: Cred struct pointer representing the next credential
// return: a Cred struct pointer to a credential with the specified fields
struct Cred* cred(char* username, char* password, struct Cred* next);

// goal: frees a list of credentials
// param head: pointer to first credential in the list
void cred_free(struct Cred* head);

// goal: gets the username from a Cred struct
// param head: pointer to a Cred struct
// return: a char* representing the username of the credential
char* get_username(struct Cred* head);

// goal: gets the password from a Cred struct
// param head: pointer to a Cred struct
// return: a char* representing the password of the credential
char* get_password(struct Cred* head);

// goal: gets the pointer to the next credential in a list
// param head: pointer to a Cred struct at the head of a list
// return: a pointer to the next Cred struct in the list
struct Cred* get_next(struct Cred* head);

// goal: sets the username of a Cred struct
// param head: pointer to Cred struct to change username of
// param username: char* representing new username
void set_username(struct Cred* head, char* username);

// goal: sets the password of a Cred struct
// param head: pointer to Cred struct to change password of
// param password: char* representing new password
void set_password(struct Cred* head, char* password);

// goal: sets the next credential in a list of credentials
// param head: pointer to Cred struct to change successor of
// param next: pointer to new successor credential
void set_next(struct Cred* head, struct Cred* next);

#endif
