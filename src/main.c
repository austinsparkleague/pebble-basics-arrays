#include <pebble.h>
/*this is an example of how variables work in C.  For now, ignore all of the set up code for the app, and we are just going to focus on a small bit of
code that focuses on how you can store information in variables.*/
  
  
  
Window *my_window;
TextLayer *text_layer;

static void main_window_load(Window *window){
  //Here is where we are going to work for this project---------------------------------------
  
  // Instead of creating one word, we are going to create an array of words.  Arrays are just what the name implies,
  // it is a group of the same thing.  In this case, we are doing an array, or stack of word
  // In C, you also always need to tell the compiler how many items are in that stack.
  // Let's make an array that has 4 elements in it, we do so by putting the number of elements that we would like to have in the 
  // array, inside the square brackets like so...
  char *array_of_words[4];
  
  //great, now let's assign a value to each of the elements in the array, one at a time.  Notice that arrays start counting from zero,
  //so we told it we wanted four elements, and so the array created four elements with index numbers to find them, starting with zero.
  //so to assign the value of the first element, we are going do the following:
  array_of_words[0] = "hi";
  //and for the 2nd element
  array_of_words[1] = "how";
  //and the third
  array_of_words[2] = "are";
  //and now for the fourth...
  array_of_words[3] = "you";
  
  
  //now, in order to refer to those values, we can use just an integer, like 1,2,3 etc. or we
  //can create a variable and store an integer inside of that variable, like this.
  int index_number = 1;
  
  //  so later on in the code, we show the text in the layer with the line that goes:
  //  text_layer_set_text(text_layer, array_of_words[index_number] );
  //  now given that, how do you think we could change the code to display the word "you"
  //  instead of "how"?
  
  
  
 //------------------------------------------------------------------------------------------
  
  Layer *window_layer = window_get_root_layer(window);
  text_layer = text_layer_create(GRect(0, 0, 144, 60));
  text_layer_set_text(text_layer, array_of_words[index_number] );
  text_layer_set_text_color(text_layer, GColorBlack);
  
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

}

static void main_window_unload(){
   text_layer_destroy(text_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
