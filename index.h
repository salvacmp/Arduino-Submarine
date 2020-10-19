const char MAIN_page[] PROGMEM = R"=====(
<head>
    <title>Remote Control</title>
    <meta name="viewport" content="height=device-height, initial-scale=1.0">
    <style>
        * {
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Lato', sans-serif;
            text-align: center;
            background-color: #455a64;
        }
        
        h1 {
            color: white;
            font-size: 3em;
            font-weight: 300;
            letter-spacing: 0.1em;
        }
        
        button {
            display: block;
            border-radius: 100%;
            border: none;
            outline: none;
            margin: 20px;
            padding: 20px;
            background-color: #03a9f4;
            box-shadow: 3px 3px 7px #333;
        }
        
        button:active {
            box-shadow: none;
        }
        
        svg {
            fill: white;
            width: 64px;
            height: 64px;
        }
        
        section {
            display: inline-block;
        }
        
        .remote-buttons {
            position: relative;
        }
        
        .remote {
            display: inline-block;
            padding: 32px 0;
        }
        
        .power {
            background-color: #ff1538;
        }
        
        .source {
            background-color: #ff8f01;
        }
        
        .img-l {
            float: left;
            width: 100px;
            height: 100px;
            background: #0000;
        }
        
        .header h1 {
            position: relative;
            top: 18px;
            left: 10px;
            right: 10px;
        }
        
        .img-r {
            float: right;
            width: 100px;
            height: 100px;
            background: #0000;
        }
        
        .copy-left {
            display: inline-block;
            text-align: right;
            margin: 0px;
            -moz-transform: scaleX(-1);
            -o-transform: scaleX(-1);
            -webkit-transform: scaleX(-1);
            transform: scaleX(-1);
            filter: FlipH;
            -ms-filter: “FlipH”;
        }
    </style>

</head>

<body>
    <div class="remote">
        <div class="header">
            <img class="img-l" src="ico.png" />
            <h1>Wifi</h1>

        </div>
        <div>
            <h4>Current Time: <span id="time" /></h4>
        </div>
        <div class="remote-buttons">
            <section>
                <button id="power" class="maju" onclick="location.href='/MJ';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNMTcuNTA0IDI2LjAyNWwuMDAxLTE0LjI4NyA2LjM2NiA2LjM2N0wyNiAxNS45NzkgMTUuOTk3IDUuOTc1IDYgMTUuOTcxIDguMTI5IDE4LjFsNi4zNjYtNi4zNjh2MTQuMjkxeiIvPjwvc3ZnPg=='/>

   </button>
                <button id="source" class="kiri" onclick="location.href='/KR';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNMjYuMDI1IDE0LjQ5NmwtMTQuMjg2LS4wMDEgNi4zNjYtNi4zNjZMMTUuOTc5IDYgNS45NzUgMTYuMDAzIDE1Ljk3MSAyNmwyLjEyOS0yLjEyOS02LjM2Ny02LjM2NmgxNC4yOXoiLz48L3N2Zz4='/>
   </button>
                <button id="source" class="bawah" onclick="location.href='/ATS';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNOCAyMC42OTVsNy45OTctMTEuMzlMMjQgMjAuNjk1eiIvPjwvc3ZnPg=='/>
   </button>
            </section>
            <section class="vol-section">
                <button id="vol-up" class="power" onclick="location.href='/STP2';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNNy4wMDQgMjMuMDg3bDcuMDgtNy4wODEtNy4wNy03LjA3MUw4LjkyOSA3LjAybDcuMDY3IDcuMDY5TDIzLjA4NCA3bDEuOTEyIDEuOTEzLTcuMDg5IDcuMDkzIDcuMDc1IDcuMDc3LTEuOTEyIDEuOTEzLTcuMDc0LTcuMDczTDguOTE3IDI1eiIvPjwvc3ZnPg=='/>
   </button>
                <button id="vol-down" class="power" onclick="location.href='/RST';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNNy4wMDQgMjMuMDg3bDcuMDgtNy4wODEtNy4wNy03LjA3MUw4LjkyOSA3LjAybDcuMDY3IDcuMDY5TDIzLjA4NCA3bDEuOTEyIDEuOTEzLTcuMDg5IDcuMDkzIDcuMDc1IDcuMDc3LTEuOTEyIDEuOTEzLTcuMDc0LTcuMDczTDguOTE3IDI1eiIvPjwvc3ZnPg=='/>
	</button>
                <button id="vol-down" class="power" onclick="location.href='/STP1';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNNy4wMDQgMjMuMDg3bDcuMDgtNy4wODEtNy4wNy03LjA3MUw4LjkyOSA3LjAybDcuMDY3IDcuMDY5TDIzLjA4NCA3bDEuOTEyIDEuOTEzLTcuMDg5IDcuMDkzIDcuMDc1IDcuMDc3LTEuOTEyIDEuOTEzLTcuMDc0LTcuMDczTDguOTE3IDI1eiIvPjwvc3ZnPg=='/>
	</button>
            </section>

            <section class="lr-section">
                <button id="left" onclick="location.href='/MD';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNMTQuNDk2IDUuOTc1bC0uMDAxIDE0LjI4Ny02LjM2Ni02LjM2N0w2IDE2LjAyMWwxMC4wMDMgMTAuMDA0TDI2IDE2LjAyOSAyMy44NzEgMTMuOWwtNi4zNjYgNi4zNjhWNS45Nzd6Ii8+PC9zdmc+'/>
   </button>
                <button id="right" onclick="location.href='/KN';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNNS45NzUgMTcuNTA0bDE0LjI4Ny4wMDEtNi4zNjcgNi4zNjZMMTYuMDIxIDI2bDEwLjAwNC0xMC4wMDNMMTYuMDI5IDZsLTIuMTI4IDIuMTI5IDYuMzY3IDYuMzY2SDUuOTc3eiIvPjwvc3ZnPg=='/>
	</button>
                <button id="vol-down" onclick="location.href='/BWH';">
    <img src='data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIzMiIgaGVpZ2h0PSIzMiIgdmlld0JveD0iMCAwIDMyIDMyIj48cGF0aCBkPSJNMjQgMTEuMzA1bC03Ljk5NyAxMS4zOUw4IDExLjMwNXoiLz48L3N2Zz4='/>
	</button>
            </section>
        </div>
    </div>
    <script type="text/javascript">
        function updateTime() {
            var currentTime = new Date();
            var hours = currentTime.getHours();
            var minutes = currentTime.getMinutes();
            var seconds = currentTime.getSeconds();
            if (minutes < 10) {
                minutes = "0" + minutes;
            }
            if (seconds < 10) {
                seconds = "0" + seconds;
            }
            var v = hours + ":" + minutes + ":" + seconds + " ";
            if (hours > 11) {
                v += "PM";
            } else {
                v += "AM"
            }
            setTimeout("updateTime()", 1000);
            document.getElementById('time').innerHTML = v;
        }
        updateTime();
        //-->
    </script>
    <br>
    <span class="copy-left">©</span> 2020 Salvatore Cahyo </marquee>
    <br>
    <p>
        As Project for SMK Katolik Santo Mikael Surakarta
    </p>
</body>


)=====";
