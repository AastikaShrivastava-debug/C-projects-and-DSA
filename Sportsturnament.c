include "tournament.h"

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif

    int choice;
    loadTournamentData();
    if (current_sport == SPORT_NONE) selectSportMenu();

    do {
        printf("\n+-------------------------------------------------------------------------+\n");
        printf("|              UNIVERSAL TOURNAMENT DASHBOARD                             |\n");
        printf("|              Format: %-18s | Sport: %-16s |\n", getFormatName(current_format), getSportName(current_sport));
        printf("+-------------------------------------------------------------------------+\n");
        printf("|  1. Register Teams (Supports Odd & Even N)                              |\n");
        printf("|  2. Select Tournament Formation Format                                  |\n");
        printf("|  3. Auto-Generate Schedule (With BYEs)                                  |\n");
        printf("|  4. Enter / Update Match Result                                         |\n");
        printf("|  5. View Live Points Table & Leaderboard                                |\n");
        printf("|  6. View Match Schedule & Results                                       |\n");
        printf("|  7. Interactive Knockout Bracket Tree Diagram                           |\n");
        printf("|  8. Switch Active Sport Type                                            |\n");
        printf("|  9. Save Tournament Data to File                                        |\n");
        printf("| 10. Load Tournament Data from File                                      |\n");
        printf("| 11. Exit System                                                         |\n");
        printf("+-------------------------------------------------------------------------+\n");
        printf("Enter choice (1-11): ");

        if (scanf("%d", &choice) != 1) { 
            int c; 
            while ((c = getchar()) != '\n' && c != EOF); 
            continue; 
        }
        int c; 
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1: registerTeams(); break;
            case 2: selectFormatMenu(); break;
            case 3: generateCircleSchedule(); break;
            case 4: updateMatchResults(); break;
            case 5: displayStandings(); break;
            case 6: displayMatchSchedule(); break;
            case 7: manageKnockoutBracket(); break;
            case 8: selectSportMenu(); break;
            case 9: saveTournamentData(); break;
            case 10: loadTournamentData(); break;
            case 11: saveTournamentData(); printf("[+] Goodbye!\n"); break;
        }
    } while (choice != 11);

    return 0;
}