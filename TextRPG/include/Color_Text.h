#pragma once

#include "Character.h"
#include "Monster.h"
#include "Job.h"
#include "NowUser.h"
#include "Image.h"
#include "Inventory.h"
#include "Item.h"
#include "Shop.h"
#include "battle.h" 

using namespace std;

// ANSI 이스케이프 코드를 정의하여 사용을 간편하게 합니다.
namespace ANSI {
    const string RESET = "\033[0m";    // 모든 속성 초기화
    const string BOLD = "\033[1m";     // 굵게

    // 글씨색
    const string BLACK = "\033[30m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string WHITE = "\033[37m";

    // 배경색
    const string BG_BLACK = "\033[40m";
    const string BG_RED = "\033[41m";
    const string BG_GREEN = "\033[42m";
    const string BG_YELLOW = "\033[43m";
    const string BG_BLUE = "\033[44m";
    const string BG_MAGENTA = "\033[45m";
    const string BG_CYAN = "\033[46m";
    const string BG_WHITE = "\033[47m";
}