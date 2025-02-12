<h1 align="center">Controle de Servomotor e LED Azul com PWM - Embarcatech 💻</h1>

<p>Este projeto utiliza a biblioteca Pico SDK para controlar um servomotor e um LED RGB, com foco na cor azul, utilizando modulação por largura de pulso (PWM). O servomotor é controlado para se mover entre as posições de 0° e 180°, enquanto o LED azul (conectado ao pino GPIO 12) altera sua intensidade de acordo com a posição do servomotor.</p>

<h2>Objetivo</h2>
<p>Este código implementa um controle básico de servomotor e LED RGB com a seguinte funcionalidade:</p>
<ul>
    <li>Movimentação do servomotor entre 0° e 180°.</li>
    <li>Controle da intensidade da cor azul do LED RGB (conectado ao GPIO 12) baseado na posição do servomotor.</li>
    <li>Transições suaves entre os ângulos do servomotor (movimento gradual de 0° a 180° e vice-versa).</li>
</ul>

<h2>Hardware Requerido</h2>
<ul>
    <li>Raspberry Pi Pico (ou Raspberry Pi Pico W)</li>
    <li>Servomotor (micro servo padrão)</li>
    <li>LED RGB (com 4 pinos ou 3 pinos, focado na cor azul, conectado ao GPIO 12)</li>
</ul>

<h2>Pinos Utilizados</h2>
<ul>
    <li>GPIO 22: Controla o servomotor (PWM).</li>
    <li>GPIO 12: Controla o LED azul (PWM).</li>
</ul>

<h2>Descrição do Código</h2>
<h3>Funções Principais</h3>
<ul>
    <li><strong>configurar_pwm(pino):</strong> Configura o pino especificado para emitir PWM, ajustando a frequência para 50Hz (período de 20ms).</li>
    <li><strong>ajustar_posicao_servo(pino, largura_pulso_us):</strong> Ajusta a posição do servomotor com base no valor de largura_pulso_us (em microssegundos), que define a posição do braço do servo.</li>
    <li><strong>ajustar_brilho_led(pino, intensidade):</strong> Ajusta o brilho do LED azul com base no valor da intensidade, que varia entre 0 (apagado) e 255 (máximo brilho).</li>
</ul>

<h3>Fluxo Principal (Função main)</h3>
<ul>
    <li><strong>Movimentação do Servomotor:</strong> O código move o servomotor entre as posições de 0°, 90° e 180° por 5 segundos cada, além de realizar um movimento suave entre essas posições.</li>
    <li><strong>Controle do LED Azul:</strong> O LED azul muda sua intensidade com base na posição do servomotor:
        <ul>
            <li>Quando o servo está em 180°, o LED acende com intensidade máxima (255).</li>
            <li>Quando o servo está em 90°, o LED tem intensidade média (127).</li>
            <li>Quando o servo está em 0°, o LED é apagado (intensidade 0).</li>
        </ul>
    </li>
    <li>Durante o movimento suave do servomotor, a intensidade do LED também varia gradualmente.</li>
</ul>

<h2>Instruções para Execução</h2>
<ol>
    <li><strong>Conecte o Servomotor e o LED ao Raspberry Pi Pico:</strong>
        <ul>
            <li>Conecte o pino de controle do servomotor ao GPIO 22.</li>
            <li>Conecte o pino de controle da cor azul do LED RGB ao GPIO 12.</li>
        </ul>
    </li>
    <li><strong>Compile o Código:</strong> Certifique-se de que o ambiente de desenvolvimento do Pico SDK está configurado corretamente. Você pode configurar o ambiente seguindo o guia de instalação do Pico SDK.
        <br>Compile o código usando a ferramenta CMake para gerar o arquivo binário correspondente. Use o comando:
        <pre>cmake .</pre>
        <pre>make</pre>
    </li>
    <li><strong>Carregue o Código para o Raspberry Pi Pico:</strong> Transfira o arquivo binário gerado para o Raspberry Pi Pico utilizando o modo de bootloader (pressionando o botão BOOTSEL enquanto conecta o dispositivo ao computador).</li>
    <li><strong>Observe o Comportamento:</strong> O servomotor deverá se mover entre as posições de 0°, 90° e 180° e realizar um movimento suave. O LED azul deverá variar sua intensidade conforme a posição do servomotor.</li>
</ol>

<h2>Exemplo de Saída Esperada</h2>
<ul>
    <li>Quando o servomotor estiver em 180°: O LED azul estará com brilho máximo.</li>
    <li>Quando o servomotor estiver em 90°: O LED azul terá brilho médio.</li>
    <li>Quando o servomotor estiver em 0°: O LED azul estará apagado.</li>
    <li>Durante o movimento suave: O LED azul vai gradualmente acender e apagar de acordo com a posição do servomotor.</li>
</ul>

<h2>Observações</h2>
<p>O controle de intensidade do LED é feito com base na posição do servomotor. O movimento do servomotor influencia diretamente o brilho do LED. A frequência de PWM foi ajustada para 50Hz, o que é comum para controle de servomotores.</p>

<h2>Imagens</h2>

 <p align="center">
  <img src="https://github.com/MarianaBarretto/Controle-de-servomotor-por-PWM/blob/main/Imagem.jpg" alt="Controle de Servomotor por PWM" />
  </p>


<h3>Vídeo de Demostração</h3>

<p>Google Drive: https://drive.google.com/file/d/1wSQSzaz3Aft-jEEMfEuM3vtzBwWLlG_i/view</p>
<p>YouTube: https://www.youtube.com/watch?v=i_-g6UmOrxY</p>

<h4>Autor: <strong>Mariana Barretto</strong></h4>
