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

# ifdef __APPLE__
# include "mlx_macos/mlx.h"
# else
# include "mlx_linux/mlx.h"
# endif

//	Video Resolution
# define WIN_W	1920.0
//	Video Resolution
# define WIN_H	1080.0

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


typedef struct s_texture_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	int		bpp_n;
	int		l_len_n;
	int		endian_n;

	int		bpp_s;
	int		l_len_s;
	int		endian_s;

	int		bpp_w;
	int		l_len_w;
	int		endian_w;

	int		bpp_e;
	int		l_len_e;
	int		endian_e;

	int		bpp_c;
	int		l_len_c;
	int		endian_c;

	char	*addr_n;
	char	*addr_s;
	char	*addr_w;
	char	*addr_e;
	char	*addr_c;
}	t_texture_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	char		**map;
	int			width;
	int			height;

	char		*n_img;
	char		*s_img;
	char		*e_img;
	char		*w_img;

	char		*n_xpm;
	char		*s_xpm;
	char		*e_xpm;
	char		*w_xpm;

	double		field_of_view;

	double		x_player;
	double		y_player;

	double		x_step;
	double		y_step;

	int			x_m;
	int			y_m;

	char		dir;

	double		distance;
	double		corrected_distance;

	int			ceilling;
	int			floor;

	double		where;

	double		dst_to_projection;
	double		projection_3d;
	double		flo_cei;
	char		*color;

	t_parsing	*parsing;
	t_texture_data	my_mlx;
}	t_mlx;

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
// Loads XPM images for rendering and stores their data in the provided window structure.
void	images_to_xpm(t_mlx *window);
// Find the initial player position.
void	get_player_position(t_mlx *window);

//testers
void print_parsing_info(t_parsing *parsing);
void print_index_info(t_index *index);
void print_map(t_parsing *parsing);
#endif