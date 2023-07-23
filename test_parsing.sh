#!/bin/bash

# Compile o código
make

# Verifique se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
  echo -e "\033[0;32mCompilation successful!\033[0m"
else
  echo -e "\033[0;31mCompilation failed. Exiting...\033[0m"
  exit 1
fi

# Função para testar o ft_parsing com um arquivo de mapa
test_parsing() {
  map_file="$1"
  output_file="output.txt"

  echo -e "\nRunning cub3d with $map_file...\n"
  ./cub3d "$map_file" > "$output_file"  # Redireciona a saída para o arquivo output.txt

  # Exibe o conteúdo do arquivo output.txt com o comando cat
  cat "$output_file"

  # Remove o arquivo output.txt após visualizar o conteúdo
  rm "$output_file"
}

# Teste o ft_parsing com mapas válidos
echo -e "\n\033[1;33mTesting invalid maps...\033[0m"
test_parsing maps/map1.cub
test_parsing maps/map2.cub

# Teste o ft_parsing com um mapa inválido
echo -e "\n\033[1;33mTesting valid map...\033[0m"
test_parsing maps/map3.cub

# Limpeza
make fclean



