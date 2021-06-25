void dictionary(char (&chosenWord)[5], int choice)
{
    switch(choice)
    {
    case 1:
        chosenWord[0] = 'k';
        chosenWord[1] = 'a';
        chosenWord[2] = 'm';
        chosenWord[3] = 's';
        chosenWord[4] = 'i';
        break;
    case 2:
        chosenWord[0] = 'a';
        chosenWord[1] = 'b';
        chosenWord[2] = 'o';
        chosenWord[3] = 'r';
        chosenWord[4] = 't';
        break;
    case 3:
        chosenWord[0] = 'e';
        chosenWord[1] = 'a';
        chosenWord[2] = 'g';
        chosenWord[3] = 'e';
        chosenWord[4] = 'r';
        break;
    case 4:
        chosenWord[0] = 't';
        chosenWord[1] = 'r';
        chosenWord[2] = 'a';
        chosenWord[3] = 's';
        chosenWord[4] = 'h';
        break;
    case 5:
        chosenWord[0] = 'd';
        chosenWord[1] = 'u';
        chosenWord[2] = 's';
        chosenWord[3] = 't';
        chosenWord[4] = 'y';
        break;
    case 6:
        chosenWord[0] = 'c';
        chosenWord[1] = 'h';
        chosenWord[2] = 'e';
        chosenWord[3] = 'c';
        chosenWord[4] = 'k';
    case 7:
        chosenWord[0] = 'a';
        chosenWord[1] = 'c';
        chosenWord[2] = 'u';
        chosenWord[3] = 't';
        chosenWord[4] = 'e';
    case 8:
        chosenWord[0] = 's';
        chosenWord[1] = 'p';
        chosenWord[2] = 'e';
        chosenWord[3] = 'a';
        chosenWord[4] = 'r';
    case 9:
        chosenWord[0] = 'g';
        chosenWord[1] = 'l';
        chosenWord[2] = 'a';
        chosenWord[3] = 'z';
        chosenWord[4] = 'e';
    case 10:
        chosenWord[0] = 'f';
        chosenWord[1] = 'i';
        chosenWord[2] = 'z';
        chosenWord[3] = 'z';
        chosenWord[4] = 'y';
    default:
        break;
    }
}
