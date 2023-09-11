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
# include <X11/X.h>

# ifdef __APPLE__
# include "mlx_macos/mlx.h"
# else
# include "mlx_linux/mlx.h"
# endif

//	Video Resolution
# define SCREEN_WIDTH	1920.0
//	Video Resolution
# define SCREEN_HEIGHT	1080.0
// represents the height of one wall
# define WALL_HEIGHT 64.0
// represents half of one wall
# define HALF_WALL_HEIGHT 32.0
// Angle increment in degrees for rotation
# define ROTATION_ANGLE_INCREMENT	10.0
// // Amount of pixels to move in each step
# define PIXELS_PER_MOVE	10.0
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_parsing
{
	char	*north_path;    // Path to the north-facing texture.
	char	*south_path;    // Path to the south-facing texture.
	char	*west_path;     // Path to the west-facing texture.
	char	*east_path;     // Path to the east-facing texture.
	int		ceiling_color; // RGB color value for the ceiling.
	int		floor_color;   // RGB color value for the floor.
	char	**map;         // Maze map (2D array of characters).
	int		number_lines;  // Number of lines in the map.
}	t_parsing;

typedef struct s_index
{
	int	texture_count;         // Counter for texture data (used during parsing).
	int	color_count;        // Counter for color data (used during parsing).
	int	map_index;     // Index for the current line in the maze map.
	//int	new_line;       // Flag to indicate if a new line is encountered (used during parsing).
}	t_index;


typedef struct s_texture_data
{
	void	*img;               // Pointer to the image data.
	char	*addr;              // Pointer to the memory address of the image data.
	int		bits_per_pixel;    // Number of bits per pixel in the image.
	int		line_size;          // Size of each image line in bytes.
	int		endian;             // Endianness of the image data.

	int		bpp_north;          // Bits per pixel for the north-facing texture.
	int		l_len_north;        // Line length for the north-facing texture.
	int		endian_north;       // Endianness for the north-facing texture.

	int		bpp_south;          // Bits per pixel for the south-facing texture.
	int		l_len_south;        // Line length for the south-facing texture.
	int		endian_south;       // Endianness for the south-facing texture.

	int		bpp_west;           // Bits per pixel for the west-facing texture.
	int		l_len_west;         // Line length for the west-facing texture.
	int		endian_west;        // Endianness for the west-facing texture.

	int		bpp_east;           // Bits per pixel for the east-facing texture.
	int		l_len_east;         // Line length for the east-facing texture.
	int		endian_east;        // Endianness for the east-facing texture.

	int		bpp_ceiling;        // Bits per pixel for the ceiling texture.
	int		l_len_ceiling;      // Line length for the ceiling texture.
	int		endian_ceiling;     // Endianness for the ceiling texture.

	char	*addr_north;        // Memory address of the north-facing texture data.
	char	*addr_south;        // Memory address of the south-facing texture data.
	char	*addr_west;         // Memory address of the west-facing texture data.
	char	*addr_east;         // Memory address of the east-facing texture data.
	char	*addr_ceiling;      // Memory address of the ceiling texture data.
}	t_texture_data;


typedef struct s_mlx
{
	void		*mlx;                // Handle to the mlx instance.
	void		*window;             // Handle to the game window.
	char		**map;               // 2D array representing the game map.
	int			width;               // Width of the game window.
	int			height;              // Height of the game window.

	char		*north_texture_path; // Path to the north-facing texture image.
	char		*south_texture_path; // Path to the south-facing texture image.
	char		*east_texture_path;  // Path to the east-facing texture image.
	char		*west_texture_path;  // Path to the west-facing texture image.

	char		*n_xpm;              // North texture in XPM format.
	char		*s_xpm;              // South texture in XPM format.
	char		*e_xpm;              // East texture in XPM format.
	char		*w_xpm;              // West texture in XPM format.

	double		player_view;         // Player's field of view angle.

	double		x_player;            // Player's x-coordinate.
	double		y_player;            // Player's y-coordinate.

	double		x_step;              // Step size in the x-direction.
	double		y_step;              // Step size in the y-direction.

	int			x_m;                 // Map index in the x-direction.
	int			y_m;                 // Map index in the y-direction.

	char		player_direction;    // Direction the player is facing.

	double		ray_distance;        // Distance to the intersection point.
	double		corrected_distance;  // Corrected distance to handle fisheye effect.

	int			ceiling_color;       // Color of the ceiling.
	int			floor_color;         // Color of the floor.

	double		ray_position;        // Position of the ray in the view plane.

	double		distance_to_projection; // Distance from player to the projection plane.
	double		projection_3d;       // Height of the wall projected onto the screen.
	double		floor_ceiling_origin; // Origin position for floor and ceiling rendering.
	char		*color;              // Temporary color storage.

	t_parsing	*parsing;            // Pointer to parsing data.
	t_texture_data	display_data;      // Texture data for rendering.
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
// Calculate the distance between player and a wall.
double	distance_view(double y_player, double x_player, double y_wall, double x_wall);
// Correct the distance based on fisheye effect.
double	correct_distance(t_mlx *mlx, double angle);
//Sets the color of a pixel at the specified coordinates in the image data structure.
void	set_pixel_color(t_texture_data *data, int x, int y, int color);
// Set the player's direction based on the map coordinates.
char	set_directions(double y_coordinate, double x_coordinate, t_mlx *window);
// Renders a 3D view of the scene based on the provided distance and player direction.
void	render_3d_view(double distance, int height, t_mlx *mlx, char player_diretion);
// Retrieves the color data for the north-facing wall texture based on the given index.
char	*north_texture(t_mlx *mlx, int i);
// Retrieves the color data for the south-facing wall texture based on the given index.
char	*south_texture(t_mlx *mlx, int i);
// Retrieves the color data for the east-facing wall texture based on the given index.
char	*east_texture(t_mlx *mlx, int i);
// Retrieves the color data for the west-facing wall texture based on the given index.
char	*west_texture(t_mlx *mlx, int i);
// Performing the ray casting process to calculate rendering information.
void	calculate_Ray_Intersections(t_mlx *window, double angle, int x);
// Projects rays to render the 3D view of the scene.
void	projecting_game(t_mlx *window);
// Moves the player character backward.
void	move_backword(t_mlx *window);
// Moves the player character forward.
void	move_forward(t_mlx *window);
// Moves the player character left.
void	move_left(t_mlx *window);
// Moves the player character right.
void	move_right(t_mlx *window);
// Handles keyboard input and triggers corresponding actions.
int	get_keys(int press, t_mlx *window);

int	destroy_window(t_mlx *window);


//testers
void print_parsing_info(t_parsing *parsing);
void print_index_info(t_index *index);
void print_map(t_parsing *parsing);
#endif
