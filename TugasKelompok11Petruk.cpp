#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Fungsi untuk mencari kata secara horizontal
bool searchHorizontal(vector<string>& matrix, string word) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i].find(word) != string::npos) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk mencari kata secara vertikal
bool searchVertical(vector<string>& matrix, string word) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int j = 0; j < col; ++j) {
        string column;
        for (int i = 0; i < row; ++i) {
            column += matrix[i][j];
        }
        if (column.find(word) != string::npos) {
            return true;
        }
    }
    return false;
}

// Fungsi untuk mencari kata secara diagonal
bool searchDiagonal(vector<string>& matrix, string word) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            string diagonal;
            int r = i;
            int c = j;
            while (r < row && c < col) {
                diagonal += matrix[r][c];
                ++r;
                ++c;
            }
            if (diagonal.find(word) != string::npos) {
                return true;
            }
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            string diagonal;
            int r = i;
            int c = j;
            while (r >= 0 && c < col) {
                diagonal += matrix[r][c];
                --r;
                ++c;
            }
            if (diagonal.find(word) != string::npos) {
                return true;
            }
        }
    }

    return false;
}

// Fungsi untuk mengkapitalkan kata yang diinputkan jika non-kapital
string toUpperString(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

int main() {
    cout << "FIND WORD TABLE\n" << endl;
    
    cout << "|A A F L K H P F S S U F I C I C L E S G N N H|" << endl;
    cout << "|S F V R E O M R W L R T T S X O Q Q N A O A O|" << endl;
    cout << "|Q E I A I F X A E I R F V F Y S X I M I N J I|" << endl;
    cout << "|W S T R L G O C A P B I A F I W I W T U A C M|" << endl;
    cout << "|F E Y A E A I S T P C R L U J K O A K C E R S|" << endl;
    cout << "|R V D A K P N D E E H D E M S N C K K F O A H|" << endl;
    cout << "|M R N E D S L C R R I W N R S A A F I T M M I|" << endl;
    cout << "|Y A A E C I E A H Y M O T A V H R S S T I S B|" << endl;
    cout << "|R J S E W E L C C E N N I E T O H W S G L S E|" << endl;
    cout << "|A T A N Y Y M O I E E S N E S I O I R E L T R|" << endl;
    cout << "|U T E N E W E B H M Y B E T N N R A I E B E N|" << endl;
    cout << "|R C L K U T E A E Q J L S G S H T G D S K O A|" << endl;
    cout << "|B H O I C A T N R R S D D E C E H O O L G I T|" << endl;
    cout << "|E N S L U A R I R S E T A L O C O H C T O H E|" << endl;
    cout << "|F Z F U D Q J Y M A D O Y I W Y G L O V E S U|" << endl;
    cout << "|T E K A L F W O N S N A E B M I E J T Z N T G|" << endl;
    cout << "|E S W P O S J X E U T U Y O Z U W A K E Z H M|" << endl;
    cout << "|K Z U H B P E Z E E R F L M S N O W B A L L H|" << endl;
    cout << "|N S N O W B O A R D Y T V W Y C L E V O H S A|" << endl;
    cout << "|A C O C R Q L G Z I Y C H O D R A Z Z I L B I|" << endl;
    cout << "|L B V K K W A N Z A A Q I N W O L P W O N S L|" << endl;
    cout << "|B F R E E Z I N G R A I N S L I L G T M E L T|" << endl;
    cout << "|H Q P Y L W H F M N F F U F P S W X N U M M V|" << endl << endl;
    
    int N;
    cout << "insert number of searched word: ";
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cout << "Word number " << (i+1) << ": ";
        cin >> words[i];
        words[i] = toUpperString(words[i]);
    }

    vector<string> matrix = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };
    
    cout << "Result: " << endl;

    for (const auto& word : words) {
        bool found = searchHorizontal(matrix, word) ||
                     searchVertical(matrix, word) ||
                     searchDiagonal(matrix, word);
        if (found) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}