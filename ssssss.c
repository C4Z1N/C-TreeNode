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
	/*if (node == NULL) return NULL;
	if (key == node->data) return node;
	else if (key < node->data) return search(node->left, key);
	else return search(node->right, key);*/
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
		printf("�� %4d��", root->data);
	}
	else {
		printf("�� NULL��");
	}
}

void arrange(struct TreeNode* root) {
	struct TreeNode* current = root;
	height = treeHeight(root) + 1;
	if (height == 0) {
		printf("\n");
		printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
		printf("��                                         ��\n");
		printf("��              Ʈ���� �����!             ��\n");
		printf("��                                         ��\n");
		printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	}
	else if (height == 1) {
		if (current->data != NULL) {
			printf("\n�� Root��\n");
			printf("�� %4d��\n", current->data);
			printf("�� �� �� ��\n");
		}
	}
	else if (height == 2) {
		printf("\n      ");
		printf("�� Root��\n");
		printf("      ");
		nullNo(current);
		printf("\n      ");
		printf("�� �� �� ��\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
		nullNo(current->left);
		printf("     ");
		nullNo(current->right);
		printf("\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
	}
	else if (height == 3) {
		int left1 = 0;
		int right1 = 0;
		printf("\n                  ");
		printf("�� Root��\n");
		printf("                  ");
		nullNo(current);
		printf("\n                  ");
		printf("�� �� �� ��\n");
		printf("      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��\n");
		printf("      ");
		if (current->left != NULL) nullNo(current->left);
		else {
			left1 = 1;
			printf("�� NULL��");
		}
		printf("                 ");
		if (current->right != NULL) nullNo(current->right);
		else {
			right1 = 1;
			printf("�� NULL��");
		}
		printf("\n      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
		if (left1 == 0) nullNo(current->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (left1 == 0) nullNo(current->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (right1 == 0) nullNo(current->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (right1 == 0) nullNo(current->right->right);
		else printf("�� NULL��");
		printf("\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
	}
	else if (height == 4) {
		int l = 0;
		int r = 0;
		int ll = 0;
		int lr = 0;
		int rl = 0;
		int rr = 0;
		printf("\n                                          ");
		printf("�� Root��\n");
		printf("                                          ");
		nullNo(current);
		printf("\n                                          ");
		printf("�� �� �� ��");
		printf("\n                  ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��\n");
		printf("                  ");
		if (current->left != NULL) nullNo(current->left);
		else {
			l = 1;
			printf("�� NULL��");
		}
		printf("                                         ");
		if (current->right != NULL) nullNo(current->right);
		else {
			r = 1;
			printf("�� NULL��");
		}
		printf("\n                  ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��\n");
		printf("      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��\n");
		printf("      ");
		if (l == 0) {
			nullNo(current->left->left);
			if (thisNull(current->left->left)) {
				ll = 1;
			}
		}
		else {
			ll = 1;
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
		}
		printf("\n      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
		if (ll == 0) nullNo(current->left->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (ll == 0) nullNo(current->left->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (lr == 0) nullNo(current->left->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (lr == 0) nullNo(current->left->right->right);
		else printf("�� NULL��");
		printf("     ");
		if (rl == 0) nullNo(current->right->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (rl == 0) nullNo(current->right->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (rr == 0) nullNo(current->right->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (rr == 0) nullNo(current->right->right->right);
		else printf("�� NULL��");
		printf("\n");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��     ");
		printf("�� �� �� ��\n");
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
		printf("�� Root��");
		printf("\n");
		printf("                                             ");
		printf("                                             ");
		nullNo(current);
		printf("\n");
		printf("                                             ");
		printf("                                             ");
		printf("�� �� �� ��");
		printf("\n");
		printf("                                          ");
		printf("�� �� �� ��");
		printf("                                             ");
		printf("                                            ");
		printf("�� �� �� ��");
		printf("\n");
		printf("                                          ");
		if (current->left != NULL) nullNo(current->left);
		else {
			l = 1;
			printf("�� NULL��");;
		}
		printf("                                             ");
		printf("                                            ");
		if (current->right != NULL) nullNo(current->right);
		else {
			r = 1;
			printf("�� NULL��");
		}
		printf("\n");
		printf("                                          ");
		printf("�� �� �� ��");
		printf("                                             ");
		printf("                                            ");
		printf("�� �� �� ��");
		printf("\n");
		printf("                  ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
		}
		printf("\n");
		printf("                  ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
		printf("                                         ");
		printf("�� �� �� ��");
		printf("\n"); 
		printf("      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
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
			printf("�� NULL��");
		}
		printf("\n");
		printf("      ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("                 ");
		printf("�� �� �� ��");
		printf("\n");
		for (int i = 0; i < 16; i++) {
			printf("�� �� �� ��");
			if (i < 15) {
				printf("     ");
			}
		}
		printf("\n");
		if (lll == 0) nullNo(current->left->left->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (lll == 0) nullNo(current->left->left->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (llr == 0) nullNo(current->left->left->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (llr == 0) nullNo(current->left->left->right->right);
		else printf("�� NULL��");
		printf("     ");
		if (lrl == 0) nullNo(current->left->right->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (lrl == 0) nullNo(current->left->right->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (lrr == 0) nullNo(current->left->right->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (lrr == 0) nullNo(current->left->right->right->right);
		else printf("�� NULL��");
		printf("     ");
		if (rll == 0) nullNo(current->right->left->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (rll == 0) nullNo(current->right->left->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (rlr == 0) nullNo(current->right->left->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (rlr == 0) nullNo(current->right->left->right->right);
		else printf("�� NULL��");
		printf("     ");
		if (rrl == 0) nullNo(current->right->right->left->left);
		else printf("�� NULL��");
		printf("     ");
		if (rrl == 0) nullNo(current->right->right->left->right);
		else printf("�� NULL��");
		printf("     ");
		if (rrr == 0) nullNo(current->right->right->right->left);
		else printf("�� NULL��");
		printf("     ");
		if (rrr == 0) nullNo(current->right->right->right->right);
		else printf("�� NULL��");
		printf("\n");
		for (int i = 0; i < 16; i++) {
			printf("�� �� �� ��");
			if (i < 15) {
				printf("     ");
			}
		}
		printf("\n");
	}
	else {
		printf("\n");
		printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
		printf("��                                               ��\n");
		printf("��                                               ��\n");
		printf("��               Ʈ���� �ʹ� Ŀ��!               ��\n");
		printf("��                                               ��\n");
		printf("��                                               ��\n");
		printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	}
}

//void nullNo(struct TreeNode* node) {
//	if (node != NULL) {
//		printf("�� %4d��", node->data);
//	}
//	else {
//		printf("�� NULL��");
//	}
//}
//
//void printIndent(int level) {
//	for (int i = 0; i < level; i++) {
//		printf("      ");
//	}
//}
//
//void arrangeHelper(struct TreeNode* node, int level) {
//	if (node == NULL) {
//		printIndent(level);
//		printf("�� �� �� ��\n");
//		printIndent(level);
//		printf("�� NULL��\n");
//		printIndent(level);
//		printf("�� �� �� ��\n");
//	}
//	else {
//		arrangeHelper(node->right, level + 1);
//
//		printIndent(level);
//		printf("�� �� �� ��\n");
//
//		printIndent(level);
//		nullNo(node);
//
//		printf("\n");
//
//		printIndent(level);
//		printf("�� �� �� ��\n");
//
//		arrangeHelper(node->left, level + 1);
//	}
//}
//
//void arrange(struct TreeNode* root) {
//	printf("\n");
//	arrangeHelper(root, 0);
//}

int main() {
	int ins = 1;
	printf("�١ڡ١ڡ١ڡ١����� Ž�� Ʈ���١ڡ١ڡ١ڡ١�\n\nƮ���� �����ϱ�\n0 �Է� �� 0�� ������ �� ���� ���ڵ��� Ʈ���� ����\nù �Է��� Ʈ���� ��Ʈ�� ����, �ִ� 5������ ���\n��Ʈ �Է�: ");
	scanf("%d", &ins);
	printf("���� ��� �Է�: ");
	if(ins != 0) root = insert(root, ins);
	while (ins > 0) {
		scanf("%d", &ins);
		if (ins == 0) break;
		insert(root, ins);
	}
	/*int key;
	printf("ã�� ��: ");
	scanf("%d", &key);
	if (search(root, key) == NULL) {
		if (key % 10 == 0 || key % 10 == 1 || key % 10 == 3 || key % 10 == 6 || key % 10 == 7 || key % 10 == 8) printf("%d�� Ʈ������ ã�� �� �����ϴ�.\n", key);
		else printf("%d�� Ʈ������ ã�� �� �����ϴ�.\n", key);
	}
	else if (search(root, key)) {
		if (key % 10 == 0 || key % 10 == 1 || key % 10 == 3 || key % 10 == 6 || key % 10 == 7 || key % 10 == 8) printf("%d�� Ʈ������ ã�� �� �ֽ��ϴ�.\n", key);
		else printf("%d�� Ʈ������ ã�� �� �ֽ��ϴ�.\n", key);
	}*/
	/*root = insert(root, 50);
	insert(root, 18);
	insert(root, 64);
	insert(root, 5);
	insert(root, 31);
	insert(root, 58);
	insert(root, 79);
	insert(root, 15);
	insert(root, 69);
	insert(root, 38);
	insert(root, 2);
	insert(root, 55);
	insert(root, 1);
	insert(root, 4);
	insert(root, 11);
	insert(root, 16);
	insert(root, 53);
	insert(root, 57);
	insert(root, 62);
	insert(root, 61);
	insert(root, 66);
	insert(root, 76);
	insert(root, 85);
	insert(root, 97);
	insert(root, 25);
	insert(root, 28);
	insert(root, 33);
	insert(root, 60);*/
	/*
	insert(root, 9);
	insert(root, 31);
	insert(root, 68);
	insert(root, 76);
	insert(root, 3);
	insert(root, 15);
	insert(root, 20);
	insert(root, 58);
	insert(root, 70);
	insert(root, 59);
	insert(root, 63);
	insert(root, 95);
	insert(root, 81);*/
	inorder(root);
	printf("\n%d��\n", treeHeight(root) + 1);
	arrange(root);
	return 0;
}
  