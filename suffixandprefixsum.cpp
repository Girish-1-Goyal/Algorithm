/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

// compute prefix and suffix sum of the array

vector<int> computePrefixSum(vector<int> &arr){
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for(int i = 1; i < n; ++i){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    return prefixSum;
}

vector<int> computeSuffixSum(vector<int> &arr){
    int n = arr.size();
    vector<int> suffixSum(n, 0);
    suffixSum[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; --i){
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }
    return suffixSum;
}

void solve(){
    vector<int> arr = {1, 3, 5, 7, 9};

    // Compute prefix and suffix sums
    vector<int> prefixSum = computePrefixSum(arr);
    vector<int> suffixSum = computeSuffixSum(arr);

    // Print prefix sum array
    cout << "Prefix Sum Array: ";
    for (int val : prefixSum) cout << val << " ";
    cout << endl;

    // Print suffix sum array
    cout << "Suffix Sum Array: ";
    for (int val : suffixSum) cout << val << " ";
    cout << endl;

    // Example range sum query
    int l = 1, r = 3;
    cout << "Range Sum [" << l << ", " << r << "] using Prefix Sum: "
         << queryRangeSumPrefix(l, r, prefixSum) << endl;
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}

/*

{
    "name": "Monokai Dark",
    "author": "Optimized by Girish Kumar Goyal",
    "variables": {
        "black": "hsl(0, 0%, 5%)",
        "dark_grey": "hsl(0, 0%, 50%)",
        "blue": "hsl(210, 100%, 65%)",
        "dark_green": "hsl(140, 100%, 50%)",
        "orange": "hsl(25, 100%, 60%)",
        "purple": "hsl(260, 90%, 70%)",
        "red": "hsl(0, 90%, 65%)",
        "white": "hsl(0, 0%, 95%)",
        "yellow": "hsl(50, 100%, 60%)",
        "cyan": "hsl(180, 90%, 60%)",
        "pink": "hsl(330, 90%, 70%)",
        "teal": "hsl(160, 90%, 55%)",
        "magenta": "hsl(300, 90%, 70%)",
        "light_blue": "hsl(200, 90%, 75%)",
        "deep_orange": "hsl(15, 100%, 65%)",
        "bright_violet": "hsl(275, 100%, 75%)",
        "neon_green": "hsl(120, 100%, 55%)",
        "gold": "hsl(45, 100%, 70%)",
        "deep_blue": "hsl(220, 100%, 65%)",
        "crimson": "hsl(350, 90%, 65%)",
        "turquoise": "hsl(175, 90%, 65%)",
        "olive": "hsl(80, 70%, 50%)",
        "plum": "hsl(290, 90%, 75%)",
        "coral": "hsl(10, 90%, 70%)",
        "silver": "hsl(0, 0%, 85%)",
        "bronze": "hsl(30, 80%, 65%)"
    },
    "globals": {
        "foreground": "var(white)",
        "background": "var(black)",
        "caret": "var(blue)",
        "selection": "color(var(blue) alpha(0.3))",
        "selection_border": "var(blue)",
        "misspelling": "var(red)",
        "line_highlight": "color(var(yellow) alpha(0.2))"
    },
    "rules": [
        {
            "name": "Comment",
            "scope": "comment",
            "foreground": "var(dark_grey)",
            "font_style": "italic"
        },
        {
            "name": "String",
            "scope": "string",
            "foreground": "var(dark_green)",
            "font_style": "italic bold"
        },
        {
            "name": "Keyword",
            "scope": "keyword",
            "foreground": "var(red)",
            "font_style": "bold"
        },
        {
            "name": "Number",
            "scope": "constant.numeric",
            "foreground": "var(purple)",
            "font_style": "italic bold"
        },
        {
            "name": "Function Name",
            "scope": "entity.name.function",
            "foreground": "var(blue)",
            "font_style": "bold underline"
        },
        {
            "name": "Class Name",
            "scope": "entity.name.class",
            "foreground": "var(orange)",
            "font_style": "bold italic underline"
        },
        {
            "name": "Preprocessor Directive (#define)",
            "scope": "meta.preprocessor",
            "foreground": "var(orange)",
            "font_style": "bold italic underline"
        },
        {
            "name": "Struct Name",
            "scope": "entity.name.struct",
            "foreground": "var(deep_orange)",
            "font_style": "bold italic underline"
        },
        {
            "name": "Variable",
            "scope": "variable",
            "foreground": "var(white)"
        },
        {
            "name": "Library Function",
            "scope": "support.function",
            "foreground": "var(cyan)",
            "font_style": "italic"
        },
        {
            "name": "Library Class",
            "scope": "support.class",
            "foreground": "var(teal)",
            "font_style": "italic bold"
        },
        {
            "name": "Library Variable",
            "scope": "support.variable",
            "foreground": "var(light_blue)",
            "font_style": "italic"
        },
        {
            "name": "Tag Name",
            "scope": "entity.name.tag",
            "foreground": "var(red)",
            "font_style": "bold underline"
        },
        {
            "name": "Attribute Name",
            "scope": "entity.other.attribute-name",
            "foreground": "var(yellow)",
            "font_style": "italic"
        },
        {
            "name": "Deep Orange Accent",
            "scope": "constant.other",
            "foreground": "var(deep_orange)",
            "font_style": "italic"
        },
        {
            "name": "Bright Violet",
            "scope": "constant.character.escape",
            "foreground": "var(bright_violet)",
            "font_style": "bold"
        },
        {
            "name": "Neon Green",
            "scope": "variable.parameter",
            "foreground": "var(yellow)",
            "font_style": "italic bold"
        },
        {
            "name": "Gold Highlight",
            "scope": "entity.other.inherited-class",
            "foreground": "var(gold)",
            "font_style": "bold"
        },
        {
            "name": "Crimson Error",
            "scope": "invalid",
            "foreground": "var(crimson)",
            "font_style": "bold"
        }
    ]
}




*/