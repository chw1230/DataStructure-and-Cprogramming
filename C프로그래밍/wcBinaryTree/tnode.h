#ifndef TNODE_H
#define TNODE_H

// 이진 트리의 노드를 정의하는 구조체
struct tnode {
    char *word;             // 단어 텍스트에 대한 포인터
    int count;              // 단어의 발생 횟수
    struct tnode *left;     // 왼쪽 자식 노드에 대한 포인터
    struct tnode *right;    // 오른쪽 자식 노드에 대한 포인터
};

#endif // TNODE_H

