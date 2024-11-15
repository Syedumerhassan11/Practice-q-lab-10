
#include<stdio.h>

int max_pieces_memo(int l, int memo[]) {
if (l == 0) {
        return 0;
    }

    if (l < 0) {
        return -1;
    }
    if (memo[l] != -1) {
        return memo[l];
    }


    int cut_1 = max_pieces_memo(l - 1, memo);
    int cut_2 = max_pieces_memo(l - 2, memo);
    int cut_3 = max_pieces_memo(l - 3, memo);

    int max_cut = (cut_1 > cut_2) ? cut_1 : cut_2;
    max_cut = (cut_3 > max_cut) ? cut_3 : max_cut;

    if (max_cut == -1) {
        return -1;
    }

    memo[l] = max_cut + 1;
    return memo[l];
}
int main() {
    int length;
    printf("Enter length of rope: ");
    scanf("%d", &length);

    int memo[length + 1];
    for (int i = 0; i <= length; i++) {
        memo[i] = -1;
    }
    int result = max_pieces_memo(length, memo);
    
    if (result != -1) {
        printf("The maximum number of pieces for a rope of length %d is: %d\n", length, result);
    } else {
        printf("It's not possible to cut the rope into valid pieces.\n");
    }

    return 0;
}




























\

