//
//  main.c
//  example
//
//  Created by 연소라 on 22/02/2019.
//  Copyright © 2019 연소라. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("Hello, World!\n");
    
    int x, y, w, h;
    int sortArray[4];
    int temp;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    //경계선 최단 거리 (left, right, up, down)
    sortArray[0] = x;
    sortArray[1] = w - x;
    sortArray[2] = h - y;
    sortArray[3] = y;
    
    //가장 작은 값이 오른쪽으로 가도록 sort
    for(int i=0;i<3;i++){
        if(sortArray[i] < sortArray[i+1]){
            temp = sortArray[i];
            sortArray[i] = sortArray[i+1];
            sortArray[i+1] = temp;
        }
    }
    
    printf("%d\n", sortArray[3]);
    
    return 0;
}
