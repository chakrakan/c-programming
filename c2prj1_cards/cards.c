#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2 && c.value <= VALUE_ACE) && (c.suit >= SPADES && c.suit <= CLUBS));
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE:
    return "FULL_HOUSE"; break;
  case FLUSH:
    return "FLUSH"; break;
  case STRAIGHT:
    return "STRAIGHT"; break;
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND"; break;
  case TWO_PAIR:
    return "TWO_PAIR"; break;
  case PAIR:
    return "PAIR"; break;
  case NOTHING:
    return "NOTHING"; break;
  default:
    return "???"; break;
  }
}

char value_letter(card_t c) {
  char out;
  if (c.value >= 2 && c.value <= 9) {
    out = (char) c.value;
  } else {
    switch(c.value) {
    case 10:
      out = '0';
      break;
    case VALUE_JACK:
      out = 'J';
      break;
    case VALUE_QUEEN:
      out = 'Q';
      break;
    case VALUE_KING:
      out = 'K';
      break;
    case VALUE_ACE:
      out = 'A';
      break;
    }
  }
  return out;    
}


char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES:
    return 's'; break;
  case HEARTS:
    return 'h'; break;
  case DIAMONDS:
    return 'd'; break;
  case CLUBS:
    return 'c'; break;
  default:
    return '?'; break;
  }  
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  int value = (int)(value_let - '0');
  if (value >= 2 && value <= 9) {
    temp.value = value;
  } else {
    switch(value) {
    case 0:
      temp.value = 10;
      break;
    case 26:
      temp.value = VALUE_JACK;
      break;
    case 27:
      temp.value = VALUE_KING;
      break;
    case 33:
      temp.value = VALUE_QUEEN;
      break;
    case 17:
      temp.value = VALUE_ACE;
      break;
    }
  }
  switch(suit_let) {
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  }

  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = (c / 4) + 2;
  temp.suit = c % 4;
  return temp;
}
