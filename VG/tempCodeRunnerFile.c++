main() {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string k_temp;
//     getline(cin, k_temp);
//     int k = stoi(ltrim(rtrim(k_temp)));

//     string amount_count_temp;
//     getline(cin, amount_count_temp);
//     int amount_count = stoi(ltrim(rtrim(amount_count_temp)));

//     vector<int> amount(amount_count);
//     for (int i = 0; i < amount_count; i++) {
//         string amount_item_temp;
//         getline(cin, amount_item_temp);
//         int amount_item = stoi(ltrim(rtrim(amount_item_temp)));
//         amount[i] = amount_item;
//     }

//     int result = getSmallestSubarrayLength(k, amount);

//     fout << result << "\n";
//     fout.close();

//     return 0;
// }