#include "helpers.c"

int main(void)
{
    // Set console code page to UTF-8  on Windows
    #ifdef _WIN32
	    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	    UINT old_cp = GetConsoleOutputCP();
	    SetConsoleOutputCP(CP_UTF8);
    #endif

    char players[] = {A, B};

    Board b = board_init();
    int round = 0;

    while (!board_complete(b)) {
        char turn = players[round % 2];
        int **valid_moves = valid_moves_for(turn, b);
        board_print(b, turn);
        if (DEBUG) print_valid_moves(valid_moves);
        Move m = get_move(b, turn);
        b = board_update(b, m);
        round++;
    }

    board_print(b, players[round % 2]);
    print_winner(b);

	// Rest code page to original value
	#ifdef _WIN32
		SetConsoleOutputCP(old_cp);
	#endif

    return 0;
}


