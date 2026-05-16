#include <iostream>
#include <string>

struct Player {
    int id;
    bool isActive;
    double score;
};

void update_score(Player& p, int bonus) {
    p.score += bonus;
    p.isActive = true;
}

int main() {
    int counter = 0;

    for (int i = 0; i < 3; ++i) {
        counter += (i * 5); 
    }

    Player playerOne = {42, false, 3.14};
    
    update_score(playerOne, 50);

    std::string shortStr = "Hello"; 
    
    std::string longStr = "Very very long string to test out something that an LLM suggested me to do";

    std::cout<<"DONE"<<std::endl;
    return 0;
}