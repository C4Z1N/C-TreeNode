#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int height = 0;
int val = 0;

struct TreeNode {
	int data;
	struct TreeNode* left, *right;
};

struct TreeNode* root = NULL;

int treeHeight(struct TreeNode* root) {
	if (root == NULL) return -1;
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

struct TreeNode* search(struct TreeNode* node, int key) {
	while (node != NULL) {
		if (key == node->data) return node;
		else if (key < node->data) node = node->left;
		else node = node->right;
	}
	return NULL;
}

struct TreeNode* new_node(int key) {
	struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	new->data = key;
	new->left = NULL;
	new->right = NULL;
	return new;
}

struct TreeNode* min_value(struct TreeNode* node) {
	struct TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

struct TreeNode* insert(struct TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (node->data > key) node->left = insert(node->left, key);
	else if (node->data < key) node->right = insert(node->right, key);
	return node;
}

struct TreeNode* delete(struct TreeNode* node, int key) {
	if (node == NULL) return node;
	if (node->data > key) {
		node->left = delete(node->left, key);
	}
	else if (node->data < key) {
		node->right = delete(node->right, key);
	}
	else {
		if (node->left == NULL) {
			struct TreeNode* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			struct TreeNode* temp = node->left;
			free(node);
			return temp;
		}
		struct TreeNode* temp = min_value(node->right);
		node->data = temp->data;
		node->right = delete(node->right, temp->data);
	}
	return node;
}

void inorder(struct TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void stacking(struct TreeNode* root) {
	if (root != NULL) {
		stacking(root->left);
		val++;
		stacking(root->right);
	}
}

int thisNull(struct TreeNode* root) {
	if (root != NULL) {
		return 0;
	}
	return 1;
}

void nullNo(struct TreeNode* root) {
	if (root != NULL) {
		printf("│ %4d│", root->data);
	}
	else {
		printf("│ NULL│");
	}
}

void arrange(struct TreeNode* root) {
	struct TreeNode* current = root;
	height = treeHeight(root) + 1;
	if (height == 0) {
		printf("\n");
		printf("┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┐\n");
		printf("│                                         │\n");
		printf("│              트리가 없어요!             │\n");
		printf("│                                         │\n");
		printf("└ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┘\n");
	}
	else if (height == 1) {
		if (current->data != NULL) {
			printf("\n┌ Root┐\n");
			printf("│ %4d│\n", current->data);
			printf("└ ─ ─ ┘\n");
		}
	}
	else if (height == 2) {
		printf("\n      ");
		printf("┌ Root┐\n");
		printf("      ");
		nullNo(current);
		printf("\n      ");
		printf("└ ─ ─ ┘\n");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐\n");
		nullNo(current->left);
		printf("     ");
		nullNo(current->right);
		printf("\n");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘\n");
	}
	else if (height == 3) {
		int left1 = 0;
		int right1 = 0;
		printf("\n                  ");
		printf("┌ Root┐\n");
		printf("                  ");
		nullNo(current);
		printf("\n                  ");
		printf("└ ─ ─ ┘\n");
		printf("      ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐\n");
		printf("      ");
		if (current->left != NULL) nullNo(current->left);
		else {
			left1 = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (current->right != NULL) nullNo(current->right);
		else {
			right1 = 1;
			printf("│ NULL│");
		}
		printf("\n      ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘\n");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐\n");
		if (left1 == 0) nullNo(current->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (left1 == 0) nullNo(current->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (right1 == 0) nullNo(current->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (right1 == 0) nullNo(current->right->right);
		else printf("│ NULL│");
		printf("\n");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘\n");
	}
	else if (height == 4) {
		int l = 0;
		int r = 0;
		int ll = 0;
		int lr = 0;
		int rl = 0;
		int rr = 0;
		printf("\n                                          ");
		printf("┌ Root┐\n");
		printf("                                          ");
		nullNo(current);
		printf("\n                                          ");
		printf("└ ─ ─ ┘");
		printf("\n                  ");
		printf("┌ ─ ─ ┐");
		printf("                                         ");
		printf("┌ ─ ─ ┐\n");
		printf("                  ");
		if (current->left != NULL) nullNo(current->left);
		else {
			l = 1;
			printf("│ NULL│");
		}
		printf("                                         ");
		if (current->right != NULL) nullNo(current->right);
		else {
			r = 1;
			printf("│ NULL│");
		}
		printf("\n                  ");
		printf("└ ─ ─ ┘");
		printf("                                         ");
		printf("└ ─ ─ ┘\n");
		printf("      ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐\n");
		printf("      ");
		if (l == 0) {
			nullNo(current->left->left);
			if (thisNull(current->left->left)) {
				ll = 1;
			}
		}
		else {
			ll = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (l == 0) {
			nullNo(current->left->right);
			if (thisNull(current->left->right)) {
				lr = 1;
			}
		}
		else {
			lr = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (r == 0) {
			nullNo(current->right->left);
			if (thisNull(current->right->left)) {
				rl = 1;
			}
		}
		else {
			rl = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (r == 0) {
			nullNo(current->right->right);
			if (thisNull(current->right->right)) {
				rr = 1;
			}
		}
		else {
			rr = 1;
			printf("│ NULL│");
		}
		printf("\n      ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘\n");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐     ");
		printf("┌ ─ ─ ┐\n");
		if (ll == 0) nullNo(current->left->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (ll == 0) nullNo(current->left->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (lr == 0) nullNo(current->left->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (lr == 0) nullNo(current->left->right->right);
		else printf("│ NULL│");
		printf("     ");
		if (rl == 0) nullNo(current->right->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (rl == 0) nullNo(current->right->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (rr == 0) nullNo(current->right->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (rr == 0) nullNo(current->right->right->right);
		else printf("│ NULL│");
		printf("\n");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘     ");
		printf("└ ─ ─ ┘\n");
	}
	else if (height == 5) {
		int l = 0;
		int ll = 0;
		int lr = 0;
		int lll = 0;
		int llr = 0;
		int lrl = 0;
		int lrr = 0;
		int r = 0;
		int rl = 0;
		int rr = 0;
		int rll = 0;
		int rlr = 0;
		int rrl = 0;
		int rrr = 0;
		printf("\n");
		printf("                                             ");
		printf("                                             ");
		printf("┌ Root┐");
		printf("\n");
		printf("                                             ");
		printf("                                             ");
		nullNo(current);
		printf("\n");
		printf("                                             ");
		printf("                                             ");
		printf("└ ─ ─ ┘");
		printf("\n");
		printf("                                          ");
		printf("┌ ─ ─ ┐");
		printf("                                             ");
		printf("                                            ");
		printf("┌ ─ ─ ┐");
		printf("\n");
		printf("                                          ");
		if (current->left != NULL) nullNo(current->left);
		else {
			l = 1;
			printf("│ NULL│");;
		}
		printf("                                             ");
		printf("                                            ");
		if (current->right != NULL) nullNo(current->right);
		else {
			r = 1;
			printf("│ NULL│");
		}
		printf("\n");
		printf("                                          ");
		printf("└ ─ ─ ┘");
		printf("                                             ");
		printf("                                            ");
		printf("└ ─ ─ ┘");
		printf("\n");
		printf("                  ");
		printf("┌ ─ ─ ┐");
		printf("                                         ");
		printf("┌ ─ ─ ┐");
		printf("                                         ");
		printf("┌ ─ ─ ┐");
		printf("                                         ");
		printf("┌ ─ ─ ┐");
		printf("\n");
		printf("                  ");
		if (l == 0) {
			nullNo(current->left->left);
			if (thisNull(current->left->left)) {
				ll = 1;
			}
		}
		else {
			ll = 1;
			printf("│ NULL│");
		}
		printf("                                         ");
		if (l == 0) {
			nullNo(current->left->right);
			if (thisNull(current->left->right)) {
				lr = 1;
			}
		}
		else {
			lr = 1;
			printf("│ NULL│");
		}
		printf("                                         ");
		if (r == 0) {
			nullNo(current->right->left);
			if (thisNull(current->right->left)) {
				rl = 1;
			}
		}
		else {
			rl = 1;
			printf("│ NULL│");
		}
		printf("                                         ");
		if (r == 0) {
			nullNo(current->right->right);
			if (thisNull(current->right->right)) {
				rr = 1;
			}
		}
		else {
			rr = 1;
			printf("│ NULL│");
		}
		printf("\n");
		printf("                  ");
		printf("└ ─ ─ ┘");
		printf("                                         ");
		printf("└ ─ ─ ┘");
		printf("                                         ");
		printf("└ ─ ─ ┘");
		printf("                                         ");
		printf("└ ─ ─ ┘");
		printf("\n"); 
		printf("      ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("                 ");
		printf("┌ ─ ─ ┐");
		printf("\n");
		printf("      ");
		if (ll == 0) {
			nullNo(current->left->left->left);
			if (thisNull(current->left->left->left)) {
				lll = 1;
			}
		}
		else {
			lll = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (ll == 0) {
			nullNo(current->left->left->right);
			if (thisNull(current->left->left->right)) {
				llr = 1;
			}
		}
		else {
			llr = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (lr == 0) {
			nullNo(current->left->right->left);
			if (thisNull(current->left->right->left)) {
				lrl = 1;
			}
		}
		else {
			lrl = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (lr == 0) {
			nullNo(current->left->right->right);
			if (thisNull(current->left->right->right)) {
				lrr = 1;
			}
		}
		else {
			lrr = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (rl == 0) {
			nullNo(current->right->left->left);
			if (thisNull(current->right->left->left)) {
				rll = 1;
			}
		}
		else {
			rll = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (rl == 0) {
			nullNo(current->right->left->right);
			if (thisNull(current->right->left->right)) {
				rlr = 1;
			}
		}
		else {
			rlr = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (rr == 0) {
			nullNo(current->right->right->left);
			if (thisNull(current->right->right->left)) {
				rrl = 1;
			}
		}
		else {
			rrl = 1;
			printf("│ NULL│");
		}
		printf("                 ");
		if (rr == 0) {
			nullNo(current->right->right->right);
			if (thisNull(current->right->right->right)) {
				rrr = 1;
			}
		}
		else {
			rrr = 1;
			printf("│ NULL│");
		}
		printf("\n");
		printf("      ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("                 ");
		printf("└ ─ ─ ┘");
		printf("\n");
		for (int i = 0; i < 16; i++) {
			printf("┌ ─ ─ ┐");
			if (i < 15) {
				printf("     ");
			}
		}
		printf("\n");
		if (lll == 0) nullNo(current->left->left->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (lll == 0) nullNo(current->left->left->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (llr == 0) nullNo(current->left->left->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (llr == 0) nullNo(current->left->left->right->right);
		else printf("│ NULL│");
		printf("     ");
		if (lrl == 0) nullNo(current->left->right->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (lrl == 0) nullNo(current->left->right->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (lrr == 0) nullNo(current->left->right->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (lrr == 0) nullNo(current->left->right->right->right);
		else printf("│ NULL│");
		printf("     ");
		if (rll == 0) nullNo(current->right->left->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (rll == 0) nullNo(current->right->left->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (rlr == 0) nullNo(current->right->left->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (rlr == 0) nullNo(current->right->left->right->right);
		else printf("│ NULL│");
		printf("     ");
		if (rrl == 0) nullNo(current->right->right->left->left);
		else printf("│ NULL│");
		printf("     ");
		if (rrl == 0) nullNo(current->right->right->left->right);
		else printf("│ NULL│");
		printf("     ");
		if (rrr == 0) nullNo(current->right->right->right->left);
		else printf("│ NULL│");
		printf("     ");
		if (rrr == 0) nullNo(current->right->right->right->right);
		else printf("│ NULL│");
		printf("\n");
		for (int i = 0; i < 16; i++) {
			printf("└ ─ ─ ┘");
			if (i < 15) {
				printf("     ");
			}
		}
		printf("\n");
	}
	else {
		printf("\n");
		printf("┌ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┐\n");
		printf("│                                               │\n");
		printf("│                                               │\n");
		printf("│               트리가 너무 커요!               │\n");
		printf("│                                               │\n");
		printf("│                                               │\n");
		printf("└ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ┘\n");
	}
}

int main() {
	int ins = 1;
	printf("☆★☆★☆★☆★이진 탐색 트리☆★☆★☆★☆★\n\n트리에 삽입하기\n0 입력 시 0을 제외한 그 전의 숫자들을 트리에 삽입\n첫 입력은 트리의 루트로 고정, 최대 5층까지 출력\n루트 입력: ");
	scanf("%d", &ins);
	printf("하위 요소 입력: ");
	if(ins != 0) root = insert(root, ins);
	while (ins > 0) {
		scanf("%d", &ins);
		if (ins == 0) break;
		insert(root, ins);
	}
	inorder(root);
	printf("\n%d층\n", treeHeight(root) + 1);
	arrange(root);
	return 0;
}
  
