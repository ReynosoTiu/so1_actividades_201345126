if [ -z "$GITHUB_USER" ]; then
	GITHUB_USER=reynosotiu
fi

res_git=$(curl -s https://api.github.com/users/$GITHUB_USER)

usuario=$(echo $res_git | jq -r '.login')
id=$(echo $res_git | jq -r '.id')
creacion=$(echo $res_git | jq -r '.created_at')

res_todo="Hola $usuario. User ID: $id. Cuenta fue creada el: $creacion"

echo $res_todo

direccion="tmp/$(date +%F)"
mkdir -p $direccion

echo $res_todo >> "$direccion/saludos.log"
