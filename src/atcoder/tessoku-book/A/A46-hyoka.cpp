/*
A46の特典を計算するプログラム

[得点の計算方法（問題文より）]
各テストケースに対して、以下のように得点が定められます。ただし、合計距離をDとします。
- 出力が条件を満たさない場合：0 点
- 出力が条件を満たす場合：⌊106 ÷D⌋ 点
全部で50個のテストケースがあり、最終的な得点はそれらの合計となります。

[動作方法]
1. テストケース50個をA46/以下に置く。
2. テストプログラムの実行結果を出力するためのディレクトリを作成する。パスはoutput/とする。
3. テストしたいプログラムをコンパイルする。ファイル名はa.outとする。
4. このプログラムを-oオプションで別名の実行ファイルとしてコンパイルする。
5. 4の実行ファイルを実行する。

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double totalScore = 0.0;

    for (int testNum = 1; testNum <= 50; ++testNum) {
        // ファイル名の作成
        char inputFile[100];
        char outputFile[100];
        char command[200];
        snprintf(inputFile, sizeof(inputFile), "A46/in%02d.in", testNum);
        snprintf(outputFile, sizeof(outputFile), "output/%02d.txt", testNum);

        // 入力ファイルからNと都市の座標を読み込む
        int N;
        std::vector<double> X, Y;
        std::ifstream inFile(inputFile);
        if (!inFile) {
            std::cerr << "Failed to open input file: " << inputFile << std::endl;
            continue;
        }
        inFile >> N;
        X.resize(N + 1);  // 1-based indexing
        Y.resize(N + 1);
        for (int i = 1; i <= N; ++i) {
            inFile >> X[i] >> Y[i];
        }
        inFile.close();

        // コマンドの実行
        snprintf(command, sizeof(command), "./a.out < %s > %s", inputFile, outputFile);
        int ret = system(command);
        if (ret != 0) {
            std::cerr << "Failed to execute command for test case " << testNum << std::endl;
            continue;
        }

        // 出力ファイルから経路を読み込む
        std::vector<int> tour;
        std::ifstream outFile(outputFile);
        if (!outFile) {
            std::cerr << "Failed to open output file: " << outputFile << std::endl;
            continue;
        }
        int city;
        while (outFile >> city) {
            tour.push_back(city);
        }
        outFile.close();

        // 出力の検証
        bool valid = true;
        if (tour.size() != N + 1) {
            valid = false;
            std::cerr << "Test case " << testNum << ": Incorrect tour size. Expected " << N + 1
                      << ", got " << tour.size() << std::endl;
        } else {
            if (tour.front() != 1 || tour.back() != 1) {
                valid = false;
                std::cerr << "Test case " << testNum << ": Tour does not start and end with city 1."
                          << std::endl;
            } else {
                // 都市の訪問回数を数える
                std::map<int, int> cityCount;
                for (int c : tour) {
                    cityCount[c]++;
                }

                // 重複している都市を探す
                std::vector<int> duplicates;
                for (const auto& pair : cityCount) {
                    if (pair.second > 1 && pair.first != 1) {  // 都市1は2回現れても良い
                        duplicates.push_back(pair.first);
                    }
                }

                // 不足している都市を探す
                std::vector<int> missingCities;
                for (int i = 1; i <= N; ++i) {
                    if (cityCount.find(i) == cityCount.end()) {
                        missingCities.push_back(i);
                    }
                }

                if (!duplicates.empty() || !missingCities.empty()) {
                    valid = false;
                    if (!duplicates.empty()) {
                        std::cerr << "Test case " << testNum << ": Duplicate cities in the tour: ";
                        for (int c : duplicates) {
                            std::cerr << c << " ";
                        }
                        std::cerr << std::endl;
                    }
                    if (!missingCities.empty()) {
                        std::cerr << "Test case " << testNum << ": Missing cities in the tour: ";
                        for (int c : missingCities) {
                            std::cerr << c << " ";
                        }
                        std::cerr << std::endl;
                    }
                }

                // 都市番号が有効な範囲内かチェック
                for (int c : tour) {
                    if (c < 1 || c > N) {
                        valid = false;
                        std::cerr << "Test case " << testNum
                                  << ": Invalid city number in the tour: " << c << std::endl;
                    }
                }
            }
        }

        // 点数の計算
        if (!valid) {
            std::cerr << "Test case " << testNum << ": Invalid tour. Score is 0." << std::endl;
            continue;  // このテストケースの点数は0
        } else {
            double D = 0.0;
            for (size_t i = 0; i < tour.size() - 1; ++i) {
                int c1 = tour[i];
                int c2 = tour[i + 1];
                double dx = X[c1] - X[c2];
                double dy = Y[c1] - Y[c2];
                D += std::sqrt(dx * dx + dy * dy);
            }
            if (D == 0.0) {
                std::cerr << "Test case " << testNum << ": Total distance is 0. Score is 0."
                          << std::endl;
                continue;  // 距離が0の場合は点数0
            }
            int score = static_cast<int>(1e6 / D);
            std::cerr << "Test case " << testNum << ": Distance = " << D << ", Score = " << score
                      << std::endl;
            totalScore += score;
        }
    }

    // 合計点数の出力
    std::cout << "Total Score: " << static_cast<int>(totalScore) << std::endl;

    return 0;
}
