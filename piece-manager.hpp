#ifndef D3B264AE_83D2_4309_85D9_5D151A9D9EB3
#define D3B264AE_83D2_4309_85D9_5D151A9D9EB3

#include <array>

#include "renderer.hpp"

namespace chess
{
    class piece_manager_t
    {
    public:
        // Constructor
        piece_manager_t();
        
        // The position of a piece
        struct piece_position_t
        {
            uint8_t column { 0 };
            uint8_t row { 0 };
        };
        
        // Move a piece from one position to another
        void move(const piece_position_t& original, const piece_position_t& new_position);
        
        // Start dragging if not already dragging, stop dragging if already dragging
        void set_dragging(bool dragging) noexcept;
        
        // Update the mouse position (needed for dragging)
        void update_mouse_position(double x, double y);
        
        // Render the pieces
        void render_pieces();
        
    private:
        // The renderer used to render the stuff.
        renderer_t m_renderer;
        
        // A piece
        struct piece_t
        {
            piece_t() {}
            
            // Is the piece empty?
            bool is_empty { true };
            
            piece_position_t position;
            
            enum class army_e
            {
                WHITE, BLACK
            } army { army_e::WHITE };
            
            enum class role_e
            {
                PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING
            } role { role_e::PAWN };
        };
        
        // Dragging information
        bool m_is_dragging;
        piece_t m_dragged_piece;
        // The cursor positions are in a custom coordinate going from 0.0 to 7.0.
        double m_cursor_x;
        double m_cursor_y;
        
        // A 2D array representing the entire array of pieces on the board.
        std::array<std::array<piece_t, 8>, 8> m_pieces;
        
        // Utility functions for drawing pieces
        void draw_piece(const piece_t& piece);
        
        // Utility function for drawing dragged piece
        void draw_dragged_piece(const piece_t& piece);
        
        // Put pieces back into their starting place.
        void put_pieces_to_starting_place();
    };
}

#endif /* D3B264AE_83D2_4309_85D9_5D151A9D9EB3 */
