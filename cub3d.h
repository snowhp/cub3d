#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h> 
# include <math.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_parsing {
	char	*north_path;    // Path to the north-facing texture.
	char	*south_path;    // Path to the south-facing texture.
	char	*west_path;     // Path to the west-facing texture.
	char	*east_path;     // Path to the east-facing texture.
	int		ceiling_color; // RGB color value for the ceiling.
	int		floor_color;   // RGB color value for the floor.
	char	**map;         // Maze map (2D array of characters).
	int		number_lines;  // Number of lines in the map.
}	t_parsing;

typedef struct s_index {
	int	texture_count;         // Counter for texture data (used during parsing).
	int	color_count;        // Counter for color data (used during parsing).
	int	map_index;     // Index for the current line in the maze map.
	//int	new_line;       // Flag to indicate if a new line is encountered (used during parsing).
}	t_index;

// Check if the file ends with .cub.
void	check_file_extension(char **argv);
// Check if the program is passed a valid file argument.
int	validate_arguments(char **argv, int argc);
// Get the number of lines in a file given its file descriptor.
int	count_file_lines(int fd);
// Main parsing function to parse the input file.
void	parse_cub_file(int argc, char **argv, t_parsing *parsing);
// Check each line of the map for valid characters and player position.
void	validate_line_content(t_parsing *parsing, int index, int *player_index);
// Check if the map has a valid player position.
void	validate_map_and_player(t_parsing *parsing);
// Helper function to extract RGB color components.
int	update_color_components(char s, int *vergul, int *nbr, int *rgb);
// Check if the line contains valid color values.
int	validate_color(char *line);
// Extract the color value from a line.
int	get_color(char *line, char *str);
// Get color values from the parsing.
void	color_values(t_parsing *parsing, char *line, t_index *index);
// Error handling for parsing errors.
void	error_map(t_parsing *parsing);
// Error handling for invalid line format.
void	error_line(t_parsing *parsing);
// Error handling for invalid color values.
void	error_color(t_parsing *parsing);
// Initialize the parsing structure with default values.
void	initialize_parsing(t_parsing *parsing);
// Initialize the index structure with default values.
void	initialize_index(t_index *number);
// Assign the parsed line to the map.
void	process_map_line(t_parsing *parsing, t_index *index, char *line);
 // Extract map info from the input file.
void	get_info_map(t_parsing *parsing, char *line, t_index *index, int *n_tex);
// Read the map from the input file.
void	read_map(char *file, t_parsing *parsing);
// Check the surroundings of player characters.
void	is_invalid_player_position(t_parsing *parsing, int i, int index);
// Check the surroundings of '0' characters.
int	is_invalid_zero_position(t_parsing *parsing, int index, char *line, int i);
// Get and check the texture path.
char	*get_path_check(char *line, char *ser);
// Assign texture paths to the parsing structure.
void	assign_texture_path(t_parsing *parsing, char *line, int *number , t_index *index);
// Check if the line contains a valid texture specifier.
int	is_texture_line(char *line );
// Check if a character is a valid map character.
int	is_invalid_map_character(char c);
// Check if the line contains '0' characters.
int	contains_zero_character(char *str);

//testers
void print_parsing_info(t_parsing *parsing);
void print_index_info(t_index *index);
void print_map(t_parsing *parsing);
#endif