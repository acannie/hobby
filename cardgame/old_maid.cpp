#include <bits/stdc++.h>
using namespace std;

void display_welcome();
void make_deck(vector<pair<string, string>> *deck);
int get_CPU_num();
void hand_out_cards(vector<vector<pair<string, string>>> *players_cards,
                    vector<pair<string, string>> *deck, int player_num);
void init_ranks(const vector<vector<pair<string, string>>> &players_cards,
                vector<string> *player_statuses, int *rank);
void display_place(const vector<vector<pair<string, string>>> &player_cards,
                   int active_player, const vector<string> &player_statuses);
int get_robbed_player(const vector<string> &player_statuses, int active_player);
int get_robbed_card_index(
    const vector<vector<pair<string, string>>> &players_cards,
    int active_player, int robbed_player);
bool is_discard_found(const vector<vector<pair<string, string>>> &players_cards,
                      int active_player,
                      const pair<string, string> &robbed_card);
void update_rank(const vector<vector<pair<string, string>>> &players_cards,
                 vector<string> *player_statuses, int player, int *rank);
bool game_finished(const vector<string> &player_statuses);
bool discard(vector<pair<string, string>> *player_cards);
string notation_of_rank(int rank);
void press_enter_to_continue();
int get_next_active_player(const vector<string> &player_statuses,
                           int active_player);
void update_final_status(vector<string> *player_statuses,
                         vector<vector<pair<string, string>>> *players_cards);

void game_setup(vector<vector<pair<string, string>>> *players_cards,
                vector<string> *player_statuses, int *rank, int *player_num,
                int *active_player);
void game(vector<vector<pair<string, string>>> *players_cards,
          vector<string> *player_statuses, int *rank, int *active_player);
void game_finalize(vector<vector<pair<string, string>>> *players_cards,
                   vector<string> *player_statuses, int active_player);

const unordered_map<string, string> &kSymbolTable{{"spade", "♠"},
                                                  {"heart", "♥"},
                                                  {"club", "♣"},
                                                  {"diamond", "♦"},
                                                  {"joker", "☆"}};
const vector<string> &kCardMarks = {"spade", "heart", "club", "diamond"};
const vector<string> &kCardNums = {"A", "2", "3",  "4", "5", "6", "7",
                                   "8", "9", "10", "J", "Q", "K"};

int main() {
  // ランダム変数の宣言
  std::random_device rng;

  vector<vector<pair<string, string>>> players_cards;
  vector<string> player_statuses;
  int rank = 1;
  int player_num;

  // 最初のplayerを決定
  int active_player;
  game_setup(&players_cards, &player_statuses, &rank, &player_num,
             &active_player);

  // ゲームスタート
  game(&players_cards, &player_statuses, &rank, &active_player);

  // ゲーム終了処理
  game_finalize(&players_cards, &player_statuses, active_player);

  return 0;
}

void display_welcome() {
  vector<string> welcome_messages;
  welcome_messages.emplace_back("Welcome to Old Maid!");
  welcome_messages.emplace_back("- You can play against the computer.");
  welcome_messages.emplace_back("- Everything is up to you.");
  welcome_messages.emplace_back("- There is no cheat.");
  welcome_messages.emplace_back("Let's start!");

  int max_len = 0;
  for (auto message : welcome_messages) {
    max_len = max(max_len, (int)message.length());
  }

  for (int i = 0; i < max_len + 4; i++) {
    cout << "-";
  }
  cout << endl;
  for (auto message : welcome_messages) {
    cout << "| " << message;
    for (int i = 0; i < max_len - message.length(); i++) {
      cout << " ";
    }
    cout << " |" << endl;
  }
  for (int i = 0; i < max_len + 4; i++) {
    cout << "-";
  }
  cout << endl;
}

void make_deck(vector<pair<string, string>> *deck) {
  for (int i = 0; i < kCardMarks.size(); i++) {
    for (int j = 0; j < kCardNums.size(); j++) {
      (*deck).emplace_back(make_pair(kCardMarks.at(i), kCardNums.at(j)));
    }
  }
  (*deck).emplace_back(make_pair("joker", "jo"));
}

int get_CPU_num() {
  int CPU_num;
  const int total_cards_num = kCardMarks.size() * kCardNums.size() + 1;
  while (1) {
    cin >> CPU_num;

    if (!(1 <= CPU_num && CPU_num <= total_cards_num - 1)) {
      cout << "Input number 1 to " << total_cards_num - 1 << ". --> ";
    } else {
      cout << endl;
      break;
    }
  }
  getchar();
  return CPU_num;
}

void hand_out_cards(vector<vector<pair<string, string>>> *players_cards,
                    vector<pair<string, string>> *deck, int player_num) {
  std::random_device rng;

  const int total_cards_num = kCardNums.size() * kCardMarks.size() + 1;

  // 配られるカードの枚数が1枚多くなるplayerの数
  int remainder_num = total_cards_num % player_num;

  unordered_set<int> remainder_player;
  while (remainder_player.size() < remainder_num) {
    remainder_player.insert(rng() % player_num);
  }

  for (int i = 0; i < player_num; i++) {
    // i番目のplayerに配るカードの数
    int dealt_card_num = total_cards_num / player_num;
    if (remainder_player.find(i) != remainder_player.end()) {
      dealt_card_num += 1;
    }

    // カードを配る
    (*players_cards).emplace_back(0);
    for (int j = 0; j < dealt_card_num; j++) {
      int randam_index = rng() % (*deck).size();
      (*players_cards).at(i).emplace_back((*deck).at(randam_index));
      (*deck).erase((*deck).begin() + randam_index);
    }
  }
}

void init_ranks(const vector<vector<pair<string, string>>> &players_cards,
                vector<string> *player_statuses, int *rank) {
  int rank_count = 0;
  for (int i = 0; i < players_cards.size(); i++) {
    if (players_cards.at(i).size() == 0) {
      (*player_statuses).at(i) = notation_of_rank((*rank));
      rank_count++;
    }
  }
  (*rank) += rank_count;
}

void display_place(const vector<vector<pair<string, string>>> &players_cards,
                   int active_player, const vector<string> &player_statuses) {
  int card_width = 7;
  // 最も多い手札の数を数える
  int max_card_num = 0;
  for (auto player_cards : players_cards) {
    max_card_num = max(max_card_num, (int)player_cards.size());
  }

  cout << "--------------------------------------------------------------------"
          "----"
       << endl;
  for (int i = 0; i < players_cards.size() - 1; i++) {
    cout << "CPU " << i + 1 << ": ";
    if (i + 1 < 10) {
      cout << " ";
    }
    if (player_statuses.at(i) == "playing") {
      // CPUのカードの中身が見える
      // for (int j = 0; j < players_cards.at(i).size(); j++)
      // {
      //     cout << "[" <<
      //     correspondence_table.at(players_cards.at(i).at(j).first) << " "; if
      //     (players_cards.at(i).at(j).second.length() == 1)
      //     {
      //         cout << " ";
      //     }
      //     cout << players_cards.at(i).at(j).second << "] ";
      // }

      // CPUのカードの中身が見えない
      for (int j = 0; j < players_cards.at(i).size(); j++) {
        cout << "[XXXX] ";
      }

      for (int space_count1 = 0;
           space_count1 < max_card_num - players_cards.at(i).size();
           space_count1++) {
        for (int space_count2 = 0; space_count2 < card_width; space_count2++) {
          cout << " ";
        }
      }

      if (active_player == i) {
        cout << " <-";
      }
    } else {
      cout << player_statuses.at(i);
    }
    cout << endl;
  }

  cout << "YOU:    ";
  int your_number = players_cards.size() - 1;
  if (player_statuses.at(your_number) == "playing") {
    for (int i = 0; i < players_cards.at(your_number).size(); i++) {
      cout << "[" << kSymbolTable.at(players_cards.at(your_number).at(i).first)
           << " ";
      if (players_cards.at(your_number).at(i).second.length() == 1) {
        cout << " ";
      }
      cout << players_cards.at(your_number).at(i).second << "] ";
    }
    if (active_player == players_cards.size() - 1) {
      cout << " <-";
    }
  } else {
    cout << player_statuses.at(your_number);
  }

  cout << endl;
}

int get_robbed_player(const vector<string> &player_statuses,
                      int active_player) {
  int player_num = player_statuses.size();
  for (int i = 1; i < player_num; i++) {
    int robbed_player = ((player_num + active_player - i) % player_num);
    if (player_statuses.at(robbed_player) == "playing") {
      return robbed_player;
    }
  }
  return -1;
}

int get_robbed_card_index(
    const vector<vector<pair<string, string>>> &players_cards,
    int active_player, int robbed_player) {
  int robbed_card_index;
  if (active_player == players_cards.size() - 1) {
    cout << "Choose card index below." << endl;

    while (1) {
      cin >> robbed_card_index;

      if (!(1 <= robbed_card_index &&
            robbed_card_index <= players_cards.at(robbed_player).size())) {
        cout << "Input number 1 to " << players_cards.at(robbed_player).size()
             << " below." << endl;
      } else {
        cout << endl;
        break;
      }
    }
    getchar();
    robbed_card_index -= 1;
  } else  // active player がCPUの場合、選ぶカードはランダムに決定
  {
    std::random_device rng;
    press_enter_to_continue();
    robbed_card_index = rng() % (players_cards.at(robbed_player).size());
  }
  return robbed_card_index;
}

bool is_discard_found(const vector<vector<pair<string, string>>> &players_cards,
                      int active_player,
                      const pair<string, string> &robbed_card) {
  for (auto it = players_cards.at(active_player).begin();
       it != players_cards.at(active_player).end(); it++) {
    if ((*it).second == robbed_card.second) {
      return true;
    }
  }
  return false;
}

void update_rank(const vector<vector<pair<string, string>>> &players_cards,
                 vector<string> *player_statuses, int player, int *rank) {
  if (players_cards.at(player).size() == 0) {
    (*player_statuses).at(player) = notation_of_rank(*rank);
    (*rank)++;
  }
}

bool game_finished(const vector<string> &player_statuses) {
  int playing_count = 0;
  for (auto player_status : player_statuses) {
    if (player_status == "playing") {
      playing_count++;
    }
  }
  if (playing_count == 1) {
    return true;
  }
  return false;
}

bool discard(vector<pair<string, string>> *player_cards) {
  bool found_discard = false;
  auto it_card1 = (*player_cards).begin();
  while (it_card1 != (*player_cards).end() - 1 &&
         !((*player_cards).size() < 2)) {
    bool num_pair_found = false;
    auto it_card2 = it_card1 + 1;
    while (it_card2 != (*player_cards).end()) {
      // 2枚のカードの数字が一致していたら手札から除く
      if ((*it_card1).second == (*it_card2).second) {
        // 一致したうち2枚目のカードを除く
        (*player_cards).erase(it_card2);
        // 一致したうち1枚目のカードを除き、その位置に来た新しいカードを次の1枚目とする
        if (it_card1 + 1 != (*player_cards).end()) {
          it_card1 = (*player_cards).erase(it_card1);
        } else {
          (*player_cards).erase(it_card1);
          it_card1 = (*player_cards).end() - 1;
        }
        num_pair_found = true;
        found_discard = true;
        break;
      }
      it_card2++;
    }
    // 数字が一致したカードの組が無かった場合、1枚目のカードのイテレータを1つ進める
    if (!num_pair_found) {
      it_card1++;
    }
  }
  return found_discard;
}

string notation_of_rank(int rank) {
  string suffix;
  if (rank % 10 == 1) {
    suffix = "st";
  } else if (rank % 10 == 2) {
    suffix = "nd";
  } else if (rank % 10 == 3) {
    suffix = "rd";
  } else {
    suffix = "th";
  }
  return to_string(rank) + suffix;
}

void press_enter_to_continue() {
  cout << "Press Enter to continue..." << endl;
  while (getchar() != '\n') {
    getchar();
  }
}

int get_next_active_player(const vector<string> &player_statuses,
                           int active_player) {
  int player_num = player_statuses.size();
  for (int i = 1; i < player_num; i++) {
    int next_player = ((active_player + i) % player_num);
    if (player_statuses.at(next_player) == "playing") {
      return next_player;
    }
  }
  return -1;
}

void update_final_status(vector<string> *player_statuses,
                         vector<vector<pair<string, string>>> *players_cards) {
  for (int i = 0; i < (*player_statuses).size(); i++) {
    if ((*player_statuses).at(i) == "playing") {
      (*player_statuses).at(i) = "lose!";
      (*players_cards).at(i).erase((*players_cards).at(i).begin());
    }
  }
}

void game_setup(vector<vector<pair<string, string>>> *players_cards,
                vector<string> *player_statuses, int *rank, int *player_num,
                int *active_player) {
  // スタート画面の表示
  display_welcome();

  // ランダム変数の宣言
  std::random_device rng;

  // 山札の定義
  vector<pair<string, string>> deck;
  make_deck(&deck);

  // CPUの数
  cout << "How many CPU do you want to play against? --> ";

  *player_num = get_CPU_num() + 1;

  // カードを配る
  hand_out_cards(players_cards, &deck, *player_num);

  // Welcome Displayをlinuxのコンソールから消去して画面をクリーンにする
  system("reset");  // linux command

  // playerごとに状態（プレイ中または順位）を保持
  for (int i = 0; i < *player_num; i++) {
    (*player_statuses).emplace_back("playing");
  }

  *active_player = rng() % *player_num;

  display_place(*players_cards, *active_player, *player_statuses);
  cout << "Let's discard! ";
  press_enter_to_continue();

  // 各playerが数字が等しいカードのペアを捨てる
  for (auto it = (*players_cards).begin(); it != (*players_cards).end(); it++) {
    discard(&(*it));
  }

  // 各プレイヤーの順位を保持（初期値0）
  init_ranks(*players_cards, player_statuses, rank);
}

void game(vector<vector<pair<string, string>>> *players_cards,
          vector<string> *player_statuses, int *rank, int *active_player) {
  int player_num = (*players_cards).size();
  bool continue_game = true;
  while (continue_game) {
    display_place(*players_cards, *active_player, *player_statuses);

    // カードを取られるプレイヤーを計算
    int robbed_player = get_robbed_player(*player_statuses, *active_player);

    // 取るカードを決定
    int robbed_card_index =
        get_robbed_card_index(*players_cards, *active_player, robbed_player);
    pair<string, string> robbed_card =
        (*players_cards).at(robbed_player).at(robbed_card_index);

    // 捨てられるカードのペアがあるか確認
    bool discard_found =
        is_discard_found(*players_cards, *active_player, robbed_card);

    // 取ったカードを手札に加える
    (*players_cards)
        .at(robbed_player)
        .erase((*players_cards).at(robbed_player).begin() + robbed_card_index);
    (*players_cards).at(*active_player).emplace_back(robbed_card);

    // カードを取られたplayerの勝利判定
    update_rank(*players_cards, player_statuses, robbed_player, rank);

    // カードを手札に加えた後の様子をdisplay
    display_place(*players_cards, *active_player, *player_statuses);
    if (*active_player != player_num - 1) {
      cout << "CPU seems to have been chosen a card. ";
    }
    if (discard_found && *active_player == player_num - 1) {
      cout << "Let's discard! ";
    }
    press_enter_to_continue();

    // active player がカードを捨てる
    if (discard_found) {
      discard(&((*players_cards).at(*active_player)));

      if (*active_player == player_num - 1) {
        display_place(*players_cards, *active_player, *player_statuses);
        press_enter_to_continue();
      } else {
        display_place(*players_cards, *active_player, *player_statuses);
        cout << "CPU " << *active_player + 1 << " seems to have discarded. ";
        press_enter_to_continue();
      }
    }

    // active playerの勝利判定
    update_rank(*players_cards, player_statuses, *active_player, rank);

    // 終了判定
    if (game_finished(*player_statuses)) {
      return;
    }

    // 次のactive player
    *active_player = get_next_active_player(*player_statuses, *active_player);
  }
}

void game_finalize(vector<vector<pair<string, string>>> *players_cards,
                   vector<string> *player_statuses, int active_player) {
  // 1人残ったplayerのstatusを更新
  update_final_status(player_statuses, players_cards);
  display_place(*players_cards, active_player, *player_statuses);
}
