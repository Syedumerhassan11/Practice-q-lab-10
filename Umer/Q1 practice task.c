#include <stdio.h>
#include <stdlib.h>
typedef struct Box {
    int weight;          
    struct Box* next;    
} Box;

int calculate_total_weight(Box* box) {
    int total_weight = 0;

    while (box != NULL) {
        total_weight += box->weight;
        box = box->next;
    }

    return total_weight;
}
Box* create_box(int weight, Box* next) {
    Box* new_box = (Box*)malloc(sizeof(Box));
    new_box->weight = weight;
    new_box->next = next;
    return new_box;
}

int main() {
    Box* box1 = create_box(5, NULL);
    Box* box2_sub_box1 = create_box(2, NULL);
    Box* box2_sub_box2 = create_box(4, NULL);
    box2_sub_box1->next = box2_sub_box2;
    Box* box2 = create_box(3, box2_sub_box1);

    box1->next = box2;
    Box* box3 = box1;
    int total_weight = calculate_total_weight(box3);
    printf("Total weight of box3: %d\n", total_weight);
    free(box1);
    free(box2_sub_box1);
    free(box2_sub_box2);
    free(box2);

    return 0;
}



