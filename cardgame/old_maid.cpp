#include <bits/stdc++.h>
using namespace std;

void display_welcome();
void display_CPU_turn(vector<vector<pair<string, string>>> player_cards, unordered_map<string, string> correspondence_table, int active_player);

int main()
{
    display_welcome();

    std::random_device rng;

    vector<string> card_marks = {"spade", "heart", "club", "diamond"};
    vector<string> card_nums;
    card_nums.emplace_back("A");
    for (int i = 2; i <= 10; i++)
    {
        card_nums.emplace_back(to_string(i));
    }
    card_nums.emplace_back("J");
    card_nums.emplace_back("Q");
    card_nums.emplace_back("K");

    unordered_map<string, string> correspondence_table{{"spade", "♠"}, {"heart", "♥"}, {"club", "♣"}, {"diamond", "♦"}, {"joker", "☆"}};

    // 山札の定義
    vector<pair<string, string>> deck;
    for (int i = 0; i < card_marks.size(); i++)
    {
        for (int j = 0; j < card_nums.size(); j++)
        {
            deck.emplace_back(make_pair(card_marks.at(i), card_nums.at(j)));
        }
    }
    deck.emplace_back(make_pair("joker", "joker"));

    int total_cards_num = card_marks.size() * card_nums.size() + 1;

    // CPUの数
    cout << "How many CPU do you want to play against? --> ";

    int CPU_num;
    while (1)
    {
        cin >> CPU_num;

        if (!(1 <= CPU_num && CPU_num <= total_cards_num - 1))
        {
            cout << "Input number 1 to " << total_cards_num - 1 << ". --> ";
        }
        else
        {
            cout << endl;
            break;
        }
    }

    int player_num = CPU_num + 1;

    // カードを配る
    vector<vector<pair<string, string>>> player_cards;

    // 配られるカードの枚数が1枚多くなるplayerの数
    int remainder_num = total_cards_num % player_num;

    // 配られるカードの枚数が1枚多くなるplayerを抽選
    unordered_set<int> remainder_player;
    while (remainder_player.size() < remainder_num)
    {
        remainder_player.insert(rng() % player_num);
    }

    // カードを配る
    for (int i = 0; i < player_num; i++)
    {
        // i番目のplayerに配るカードの数
        int dealt_card_num = total_cards_num / player_num;
        if (remainder_player.find(i) != remainder_player.end())
        {
            dealt_card_num += 1;
        }

        // カードを配る
        player_cards.emplace_back(0);
        for (int j = 0; j < dealt_card_num; j++)
        {
            int randam_index = rng() % deck.size();
            player_cards.at(i).emplace_back(deck.at(randam_index));
            deck.erase(deck.begin() + randam_index);
        }
    }

    // 最初のplayerを決定
    int active_player = rng() % player_num;

    display_CPU_turn(player_cards, correspondence_table, active_player);

    // 各playerが数字が等しいカードのペアを捨てる
    for (int i = 0; i < player_num; i++)
    {
        auto it_card1 = player_cards.at(i).begin();
        while (it_card1 != player_cards.at(i).end() - 1 && !(player_cards.at(i).size() < 2))
        {
            bool num_pair_found = false;
            auto it_card2 = it_card1 + 1;
            while (it_card2 != player_cards.at(i).end())
            {
                // 2枚のカードの数字が一致していたら手札から除く
                if ((*it_card1).second == (*it_card2).second)
                {
                    // 一致したうち2枚目のカードを除く
                    player_cards.at(i).erase(it_card2);
                    // 一致したうち1枚目のカードを除き、その位置に来た新しいカードを次の1枚目とする
                    it_card1 = player_cards.at(i).erase(it_card1);
                    num_pair_found = true;
                    break;
                }
                it_card2++;
            }
            // 数字が一致したカードの組が無かった場合、1枚目のカードのイテレータを1つ進める
            if (!num_pair_found)
            {
                it_card1++;
            }
        }
    }

    // // ゲームスタート
    // bool continue_game = true;
    // while(continue_game){

    // }

    display_CPU_turn(player_cards, correspondence_table, active_player);

    return 0;
}

void display_welcome()
{
    vector<string> welcome_messages;
    welcome_messages.emplace_back("Welcome to Old Maid!");
    welcome_messages.emplace_back("- You can play against the computer.");
    welcome_messages.emplace_back("- Everything is up to you.");
    welcome_messages.emplace_back("- There is no cheat.");
    welcome_messages.emplace_back("Let's start!");

    int max_len = 0;
    for (auto message : welcome_messages)
    {
        max_len = max(max_len, (int)message.length());
    }

    for (int i = 0; i < max_len + 4; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (auto message : welcome_messages)
    {
        cout << "| " << message;
        for (int i = 0; i < max_len - message.length(); i++)
        {
            cout << " ";
        }
        cout << " |" << endl;
    }
    for (int i = 0; i < max_len + 4; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void display_CPU_turn(vector<vector<pair<string, string>>> player_cards, unordered_map<string, string> correspondence_table, int active_player)
{
    cout << "------------------------------------------------------------------------" << endl;
    for (int i = 0; i < player_cards.size() - 1; i++)
    {
        cout << "CPU " << i + 1 << ": ";
        if (i + 1 < 10)
        {
            cout << " ";
        }
        for (int j = 0; j < player_cards.at(i).size(); j++)
        {
            cout << "[XXXX] ";
        }
        if (active_player == i)
        {
            cout << " <-";
        }
        cout << endl;
    }

    cout << "YOU:    ";
    int your_number = player_cards.size() - 1;
    for (int j = 0; j < player_cards.at(your_number).size(); j++)
    {
        cout << "[" << correspondence_table.at(player_cards.at(your_number).at(j).first) << " ";
        if (player_cards.at(your_number).at(j).second.length() == 1)
        {
            cout << " ";
        }
        cout << player_cards.at(your_number).at(j).second << "] ";
        if (active_player == player_cards.size() - 1)
        {
            cout << " <-";
        }
    }
    cout << endl;
}