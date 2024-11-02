import pygame, random

# Videojuego en el que tienes que recolectar monedas con un personaje que
# se mueve con las flechas del teclado. Cuando coges una moneda, aparece
# otra en un lugar al azar de la pantalla.
# En lugar de monedas hemos usado un pinguino que tiene que coger a un pez

pygame.init()

# Configuración de la pantalla
ANCHO_PANTALLA = 800
ALTO_PANTALLA = 600
pantalla = pygame.display.set_mode((ANCHO_PANTALLA, ALTO_PANTALLA))
pygame.display.set_caption("Coin collector")

# Cargamos la imagen
imagePinguino = pygame.image.load("./Coding-games-in-Python/images/pinguino.png")
imagePececillo = pygame.image.load("./Coding-games-in-Python/images/pececillo.png")

# Obtener el rectángulo del sprite y actualizar la posición

# Pingüino
image_rect_pinguino = imagePinguino.get_rect()
posX_pinguino = random.randint(image_rect_pinguino.width, 
                      ANCHO_PANTALLA-image_rect_pinguino.width)
posY_pinguino = random.randint(image_rect_pinguino.height, 
                      ALTO_PANTALLA-image_rect_pinguino.height)
posicion_pinguino = (posX_pinguino, posY_pinguino)
image_rect_pinguino.topleft = posicion_pinguino

# Pececillo
image_rect_pececillo = imagePececillo.get_rect()
posX_pececillo = random.randint(image_rect_pececillo.width, 
                      ANCHO_PANTALLA-image_rect_pececillo.width)
posY_pececillo = random.randint(image_rect_pececillo.height, 
                      ALTO_PANTALLA-image_rect_pececillo.height)
posicion_pececillo = (posX_pececillo, posY_pececillo)
image_rect_pececillo.topleft = posicion_pececillo

# Velocidad en píxeles por fotograma
player_speed = 5

# Se usa para gestionar lo rápido se actualiza la pantalla
reloj = pygame.time.Clock()
 
final = False

# -------- Bucle Principal del Programa -----------
while not final:
    # Comprobamos los eventos
    for evento in pygame.event.get(): # El usuario hizo algo
        if evento.type == pygame.QUIT: # Si el usuario pincha sobre cerrar
           final = True
    
    # Obtener teclas presionadas para mover al jugador, también comprobamos los
    # límites de la pantalla
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and image_rect_pinguino.left > 0:
        image_rect_pinguino.x -= player_speed
    if keys[pygame.K_RIGHT] and image_rect_pinguino.right < ANCHO_PANTALLA:
        image_rect_pinguino.x += player_speed
    if keys[pygame.K_UP] and image_rect_pinguino.top > 0:
        image_rect_pinguino.y -= player_speed
    if keys[pygame.K_DOWN] and image_rect_pinguino.bottom < ALTO_PANTALLA:
        image_rect_pinguino.y += player_speed

    # Cuando el pinguino coge al pez, éste cambia de posición
    if image_rect_pinguino.colliderect(image_rect_pececillo):
        posX_pececillo = random.randint(image_rect_pececillo.width, 
                        ANCHO_PANTALLA-image_rect_pececillo.width)
        posY_pececillo = random.randint(image_rect_pececillo.height, 
                        ALTO_PANTALLA-image_rect_pececillo.height)
        posicion_pececillo = (posX_pececillo, posY_pececillo)
        image_rect_pececillo.topleft = posicion_pececillo

    # Rellenar la pantalla de blanco
    pantalla.fill((0, 0, 0)) 
 
    # Dibujamos el sprite en la posición
    pantalla.blit(imagePinguino, image_rect_pinguino)
    pantalla.blit(imagePececillo, image_rect_pececillo)
     
    #Actualizamos la pantalla
    pygame.display.flip()
 
    # Limita a 20 fotogramas por segundo (frames per second)
    reloj.tick(20)

pygame.quit()
exit()
