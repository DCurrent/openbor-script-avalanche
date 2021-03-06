// Caskey, Damon V.
// 2018-03-21
//
// Draw a grid from top of screen to
// bottom in order to test alignment of
// screen and objects. Adjust constants
// for varying needs.
void dc_draw_grid()
{
    #define INCREMENT       10  // What line spaces to draw line and text. Ex: 10 = at every tenth line.
    #define TEXT_MODE       1   // Show text readout of line position. 1 = Text on.
    #define GRID_V_X        0   // Starting position of vertical scale grid lines.
    #define GRID_V_WIDTH    10  // Horizontal width of vertical scale grid lines.
    #define SPACING_X       5   // Space from end of line to X start of text.
    #define SPACING_Y       -5  // Space from end of line to top of text.
    #define FONT            2   // Font for text.
    #define COLOR           1   // Color index for line.
    #define ALPHA           0   // Alpha setting for line.

    int pos_x_end;      // End line here.
    int pos_y_start;    // Draw line from here (y axis).
    int pos_y_end;      // End line here.
    int text_pos_x;     // Draw text here (x axis).
    int text_pos_y;     // Draw text here (y axis).

    int pos_z;          // Depth position of drawn items.
    int i;              // Loop cursor.
    int screen_x;       // Screen size (x axis).
    int screen_y;       // Screen size (y axis).

    // get screen limits.
    screen_x = openborvariant("hresolution");
    screen_y = openborvariant("vresolution");

    // Z will need to be in front of everything.
    pos_z = openborconstant("FRONTPANEL_Z")+20000;

    pos_x_end = GRID_V_X + GRID_V_WIDTH;

    // Loop each line along vertical axis from top of
    // screen to bottom.
    for(i=0; i<screen_y; i++)
    {
        // We want to draw a line at 0 and every INCREMENT pixels after.
        // If we're past 0 and not divisible by INCREMENT, then
        // exit this increment of the loop to skip drawing.
        if(i > 0)
        {
            if(i%INCREMENT != 0)
            {
                continue;
            }
        }

        // Use cursor for y position.
        pos_y_start = i;
        pos_y_end = i;

        // Draw the line.
        drawline(GRID_V_X, pos_y_start, pos_x_end, pos_y_end, pos_z, COLOR, ALPHA);

        // Handle the text.
        if(TEXT_MODE == 1)
        {
            // Space the text out
            text_pos_x = pos_x_end + SPACING_X;
            text_pos_y = pos_y_end + SPACING_Y;

            // Draw the text.
            drawstring(text_pos_x, text_pos_y, FONT, i);
        }
    }

    #undef INCREMENT
    #undef TEXT_MODE
    #undef GRID_V_X
    #undef GRID_V_WIDTH
    #undef SPACING_X
    #undef SPACING_Y
    #undef FONT
    #undef COLOR
    #undef ALPHA
}
