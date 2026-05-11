#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_PATH "./inputs/day1_inputs.txt"

int part1(FILE* file) {
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
    return ans;
}

int part2(FILE* file) {
    char opstr[256];
    int pos = 50;
    int ans = 0;
    while (fgets(opstr, sizeof(opstr), file)) {
        char opdir = opstr[0];
        int opcnt = atoi((char* )(opstr+1));
        int cnt = 0;
        if (opdir == 'R') {
            int r = (100 - pos) % 100;          // residue for k ≡ r (mod 100)
            int first = (r == 0) ? 100 : r;     // first positive k that hits 0
            if (opcnt >= first)
                cnt = 1 + (opcnt - first) / 100;
            pos = (pos + opcnt) % 100;
        }
        else if (opdir == 'L') {
            int r = pos;                         // residue for k ≡ r (mod 100)
            int first = (r == 0) ? 100 : r;     // first positive k that hits 0
            if (opcnt >= first)
                cnt = 1 + (opcnt - first) / 100;
            pos = (pos - opcnt) % 100;
            if (pos < 0) pos += 100;
        }
        ans += cnt;
    }
    return ans;
}

int main() {
    FILE* file = fopen(INPUT_PATH, "r");
    if (file == NULL) {
        return 1;
    }
    /* int ans; */
    /* ans = part1(file); */
    /* ans = part2(file); */

    printf("Ans: %d\n", part2(file));
    fclose(file);
}
