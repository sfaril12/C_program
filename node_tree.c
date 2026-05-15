
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 5
#define MAX_NAME_LEN 20

typedef struct tree_element {
    char name[MAX_NAME_LEN];
    int is_directory;  // 1 for directory, 0 for file
    int child_count;
    int level;
    struct tree_element* children[MAX_CHILDREN];
} Node;

void create_tree(Node** root, int level, const char* parent_name);
void display_tree(Node* root, int indent);
void safe_input(char* buffer, size_t size);

int main() {
    Node* root = NULL;
    create_tree(&root, 0, "ROOT");
    printf("\n\nDIRECTORY STRUCTURE:\n");
    display_tree(root, 0);
    return 0;
}

void create_tree(Node** root, int level, const char* parent_name) {
    *root = (Node*)malloc(sizeof(Node));
    if (*root == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter name of dir/file under '%s': ", parent_name);
    safe_input((*root)->name, MAX_NAME_LEN);

    printf("Enter 1 for Directory or 0 for File: ");
    scanf("%d", &(*root)->is_directory);
    getchar(); // Consume newline

    (*root)->level = level;
    (*root)->child_count = 0;
    for (int i = 0; i < MAX_CHILDREN; i++) {
        (*root)->children[i] = NULL;
    }

    if ((*root)->is_directory) {
        printf("Number of subdirectories/files for '%s'? ", (*root)->name);
        scanf("%d", &(*root)->child_count);
        getchar(); // Consume newline

        if ((*root)->child_count > MAX_CHILDREN) {
            printf("Warning: Maximum %d children allowed. Truncating to %d.\n",
                  MAX_CHILDREN, MAX_CHILDREN);
            (*root)->child_count = MAX_CHILDREN;
        }

        for (int i = 0; i < (*root)->child_count; i++) {
            create_tree(&((*root)->children[i]), level + 1, (*root)->name);
        }
    }
}

void display_tree(Node* node, int indent) {
    if (node == NULL) return;

    for (int i = 0; i < indent; i++)
        printf("  ");

    if (node->is_directory)
        printf("[Dir] %s\n", node->name);
    else
        printf("- %s\n", node->name);

    for (int i = 0; i < node->child_count; i++) {
        display_tree(node->children[i], indent + 1);
    }
}

void safe_input(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    // Remove trailing newline if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
}
