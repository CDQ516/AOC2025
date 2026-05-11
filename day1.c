#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_PATH "./inputs/day1_inputs.txt"

int part1(FILE* file) {
    if (file == NULL) {
        return 1;
    }
    char opstr[256];
    int pos = 50;
    int ans = 0;
    while (fgets(opstr, sizeof(opstr), file)) {
        char opdir = opstr[0];
        int opcnt = atoi((char* )(opstr+1));

        pos = opdir == 'R' ? pos + opcnt : pos - opcnt;
        pos = pos < 0 ? pos % 100 + 100 : pos;
        pos = pos >= 100 ? pos % 100 : pos;
        ans = pos == 0 ? ans + 1 : ans;
    }
    fclose(file);
    return ans;
}

int part2(FILE* file) {
    // TODO: implement part2
    if (file == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    FILE* file = fopen(INPUT_PATH, "r");
    int ans;
    ans = part1(file);
    /* ans = part2(); */

    printf("Ans: %d", ans);
}
