#include <webserver.h>

AsyncWebServer server(80);

/*
* This is the index.html file that is served by the webserver.
* It contains the HTML, CSS and JavaScript code for the webinterface.
*/
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>DMXAdapter</title>
    <style>
        /*! chota.css v0.8.1 | MIT License | github.com/jenil/chota */
        :root{--bg-color:#fff;--bg-secondary-color:#f3f3f6;--color-primary:#14854f;--color-lightGrey:#d2d6dd;--color-grey:#747681;--color-darkGrey:#3f4144;--color-error:#d43939;--color-success:#28bd14;--grid-maxWidth:120rem;--grid-gutter:2rem;--font-size:1.6rem;--font-color:#333;--font-family-sans:-apple-system,BlinkbroadcastAddressesystemFont,Avenir,"Avenir Next","Segoe UI","Roboto","Oxygen","Ubuntu","Cantarell","Fira Sans","Droid Sans","Helvetica Neue",sans-serif;--font-family-mono:monaco,"Consolas","Lucida Console",monospace}html{-ms-text-size-adjust:100%;-webkit-text-size-adjust:100%;-webkit-box-sizing:border-box;box-sizing:border-box;font-size:62.5%;line-height:1.15}*,:after,:before{-webkit-box-sizing:inherit;box-sizing:inherit}*{scrollbar-color:var(--color-lightGrey) var(--bg-primary);scrollbar-width:thin}::-webkit-scrollbar{width:8px}::-webkit-scrollbar-track{background:var(--bg-primary)}::-webkit-scrollbar-thumb{background:var(--color-lightGrey)}body{background-color:var(--bg-color);color:var(--font-color);font-family:Segoe UI,Helvetica Neue,sans-serif;font-family:var(--font-family-sans);font-size:var(--font-size);line-height:1.6;margin:0;padding:0}h1,h2,h3,h4,h5,h6{font-weight:500;margin:.35em 0 .7em}h1{font-size:2em}h2{font-size:1.75em}h3{font-size:1.5em}h4{font-size:1.25em}h5{font-size:1em}h6{font-size:.85em}a{color:var(--color-primary);text-decoration:none}a:hover:not(.button){opacity:.75}button{font-family:inherit}p{margin-top:0}blockquote{background-color:var(--bg-secondary-color);border-left:3px solid var(--color-lightGrey);padding:1.5rem 2rem}dl dt{font-weight:700}hr{background-color:var(--color-lightGrey);height:1px;margin:1rem 0}hr,table{border:none}table{border-collapse:collapse;border-spacing:0;text-align:left;width:100%}table.striped tr:nth-of-type(2n){background-color:var(--bg-secondary-color)}td,th{padding:1.2rem .4rem;vertical-align:middle}thead{border-bottom:2px solid var(--color-lightGrey)}tfoot{border-top:2px solid var(--color-lightGrey)}code,kbd,pre,samp,tt{font-family:var(--font-family-mono)}code,kbd{border-radius:4px;color:var(--color-error);font-size:90%;padding:.2em .4em;white-space:pre-wrap}code,kbd,pre{background-color:var(--bg-secondary-color)}pre{font-size:1em;overflow-x:auto;padding:1rem}pre code{background:none;padding:0}abbr[title]{border-bottom:none;text-decoration:underline;-webkit-text-decoration:underline dotted;text-decoration:underline dotted}img{max-width:100%}fieldset{border:1px solid var(--color-lightGrey)}iframe{border:0}.container{margin:0 auto;max-width:var(--grid-maxWidth);padding:0 calc(var(--grid-gutter)/2);width:96%}.row{-webkit-box-direction:normal;-webkit-box-pack:start;-ms-flex-pack:start;display:-webkit-box;display:-ms-flexbox;display:flex;-ms-flex-flow:row wrap;flex-flow:row wrap;justify-content:flex-start;margin-left:calc(var(--grid-gutter)/-2);margin-right:calc(var(--grid-gutter)/-2)}.row,.row.reverse{-webkit-box-orient:horizontal}.row.reverse{-webkit-box-direction:reverse;-ms-flex-direction:row-reverse;flex-direction:row-reverse}.col{-webkit-box-flex:1;-ms-flex:1;flex:1}.col,[class*=" col-"],[class^=col-]{margin:0 calc(var(--grid-gutter)/2) calc(var(--grid-gutter)/2)}.col-1{-ms-flex:0 0 calc(8.33333% - var(--grid-gutter));flex:0 0 calc(8.33333% - var(--grid-gutter));max-width:calc(8.33333% - var(--grid-gutter))}.col-1,.col-2{-webkit-box-flex:0}.col-2{-ms-flex:0 0 calc(16.66667% - var(--grid-gutter));flex:0 0 calc(16.66667% - var(--grid-gutter));max-width:calc(16.66667% - var(--grid-gutter))}.col-3{-ms-flex:0 0 calc(25% - var(--grid-gutter));flex:0 0 calc(25% - var(--grid-gutter));max-width:calc(25% - var(--grid-gutter))}.col-3,.col-4{-webkit-box-flex:0}.col-4{-ms-flex:0 0 calc(33.33333% - var(--grid-gutter));flex:0 0 calc(33.33333% - var(--grid-gutter));max-width:calc(33.33333% - var(--grid-gutter))}.col-5{-ms-flex:0 0 calc(41.66667% - var(--grid-gutter));flex:0 0 calc(41.66667% - var(--grid-gutter));max-width:calc(41.66667% - var(--grid-gutter))}.col-5,.col-6{-webkit-box-flex:0}.col-6{-ms-flex:0 0 calc(50% - var(--grid-gutter));flex:0 0 calc(50% - var(--grid-gutter));max-width:calc(50% - var(--grid-gutter))}.col-7{-ms-flex:0 0 calc(58.33333% - var(--grid-gutter));flex:0 0 calc(58.33333% - var(--grid-gutter));max-width:calc(58.33333% - var(--grid-gutter))}.col-7,.col-8{-webkit-box-flex:0}.col-8{-ms-flex:0 0 calc(66.66667% - var(--grid-gutter));flex:0 0 calc(66.66667% - var(--grid-gutter));max-width:calc(66.66667% - var(--grid-gutter))}.col-9{-ms-flex:0 0 calc(75% - var(--grid-gutter));flex:0 0 calc(75% - var(--grid-gutter));max-width:calc(75% - var(--grid-gutter))}.col-10,.col-9{-webkit-box-flex:0}.col-10{-ms-flex:0 0 calc(83.33333% - var(--grid-gutter));flex:0 0 calc(83.33333% - var(--grid-gutter));max-width:calc(83.33333% - var(--grid-gutter))}.col-11{-ms-flex:0 0 calc(91.66667% - var(--grid-gutter));flex:0 0 calc(91.66667% - var(--grid-gutter));max-width:calc(91.66667% - var(--grid-gutter))}.col-11,.col-12{-webkit-box-flex:0}.col-12{-ms-flex:0 0 calc(100% - var(--grid-gutter));flex:0 0 calc(100% - var(--grid-gutter));max-width:calc(100% - var(--grid-gutter))}@media screen and (max-width:599px){.container{width:100%}.col,[class*=col-],[class^=col-]{-webkit-box-flex:0;-ms-flex:0 1 100%;flex:0 1 100%;max-width:100%}}@media screen and (min-width:900px){.col-1-md{-webkit-box-flex:0;-ms-flex:0 0 calc(8.33333% - var(--grid-gutter));flex:0 0 calc(8.33333% - var(--grid-gutter));max-width:calc(8.33333% - var(--grid-gutter))}.col-2-md{-webkit-box-flex:0;-ms-flex:0 0 calc(16.66667% - var(--grid-gutter));flex:0 0 calc(16.66667% - var(--grid-gutter));max-width:calc(16.66667% - var(--grid-gutter))}.col-3-md{-webkit-box-flex:0;-ms-flex:0 0 calc(25% - var(--grid-gutter));flex:0 0 calc(25% - var(--grid-gutter));max-width:calc(25% - var(--grid-gutter))}.col-4-md{-webkit-box-flex:0;-ms-flex:0 0 calc(33.33333% - var(--grid-gutter));flex:0 0 calc(33.33333% - var(--grid-gutter));max-width:calc(33.33333% - var(--grid-gutter))}.col-5-md{-webkit-box-flex:0;-ms-flex:0 0 calc(41.66667% - var(--grid-gutter));flex:0 0 calc(41.66667% - var(--grid-gutter));max-width:calc(41.66667% - var(--grid-gutter))}.col-6-md{-webkit-box-flex:0;-ms-flex:0 0 calc(50% - var(--grid-gutter));flex:0 0 calc(50% - var(--grid-gutter));max-width:calc(50% - var(--grid-gutter))}.col-7-md{-webkit-box-flex:0;-ms-flex:0 0 calc(58.33333% - var(--grid-gutter));flex:0 0 calc(58.33333% - var(--grid-gutter));max-width:calc(58.33333% - var(--grid-gutter))}.col-8-md{-webkit-box-flex:0;-ms-flex:0 0 calc(66.66667% - var(--grid-gutter));flex:0 0 calc(66.66667% - var(--grid-gutter));max-width:calc(66.66667% - var(--grid-gutter))}.col-9-md{-webkit-box-flex:0;-ms-flex:0 0 calc(75% - var(--grid-gutter));flex:0 0 calc(75% - var(--grid-gutter));max-width:calc(75% - var(--grid-gutter))}.col-10-md{-webkit-box-flex:0;-ms-flex:0 0 calc(83.33333% - var(--grid-gutter));flex:0 0 calc(83.33333% - var(--grid-gutter));max-width:calc(83.33333% - var(--grid-gutter))}.col-11-md{-webkit-box-flex:0;-ms-flex:0 0 calc(91.66667% - var(--grid-gutter));flex:0 0 calc(91.66667% - var(--grid-gutter));max-width:calc(91.66667% - var(--grid-gutter))}.col-12-md{-webkit-box-flex:0;-ms-flex:0 0 calc(100% - var(--grid-gutter));flex:0 0 calc(100% - var(--grid-gutter));max-width:calc(100% - var(--grid-gutter))}}@media screen and (min-width:1200px){.col-1-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(8.33333% - var(--grid-gutter));flex:0 0 calc(8.33333% - var(--grid-gutter));max-width:calc(8.33333% - var(--grid-gutter))}.col-2-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(16.66667% - var(--grid-gutter));flex:0 0 calc(16.66667% - var(--grid-gutter));max-width:calc(16.66667% - var(--grid-gutter))}.col-3-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(25% - var(--grid-gutter));flex:0 0 calc(25% - var(--grid-gutter));max-width:calc(25% - var(--grid-gutter))}.col-4-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(33.33333% - var(--grid-gutter));flex:0 0 calc(33.33333% - var(--grid-gutter));max-width:calc(33.33333% - var(--grid-gutter))}.col-5-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(41.66667% - var(--grid-gutter));flex:0 0 calc(41.66667% - var(--grid-gutter));max-width:calc(41.66667% - var(--grid-gutter))}.col-6-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(50% - var(--grid-gutter));flex:0 0 calc(50% - var(--grid-gutter));max-width:calc(50% - var(--grid-gutter))}.col-7-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(58.33333% - var(--grid-gutter));flex:0 0 calc(58.33333% - var(--grid-gutter));max-width:calc(58.33333% - var(--grid-gutter))}.col-8-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(66.66667% - var(--grid-gutter));flex:0 0 calc(66.66667% - var(--grid-gutter));max-width:calc(66.66667% - var(--grid-gutter))}.col-9-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(75% - var(--grid-gutter));flex:0 0 calc(75% - var(--grid-gutter));max-width:calc(75% - var(--grid-gutter))}.col-10-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(83.33333% - var(--grid-gutter));flex:0 0 calc(83.33333% - var(--grid-gutter));max-width:calc(83.33333% - var(--grid-gutter))}.col-11-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(91.66667% - var(--grid-gutter));flex:0 0 calc(91.66667% - var(--grid-gutter));max-width:calc(91.66667% - var(--grid-gutter))}.col-12-lg{-webkit-box-flex:0;-ms-flex:0 0 calc(100% - var(--grid-gutter));flex:0 0 calc(100% - var(--grid-gutter));max-width:calc(100% - var(--grid-gutter))}}fieldset{padding:.5rem 2rem}legend{font-size:.8em;letter-spacing:.1rem;text-transform:uppercase}input:not([type=checkbox]):not([type=radio]):not([type=submit]):not([type=color]):not([type=button]):not([type=reset]),select,textarea,textarea[type=text]{border:1px solid var(--color-lightGrey);border-radius:4px;display:block;font-family:inherit;font-size:1em;padding:.8rem 1rem;-webkit-transition:all .2s ease;transition:all .2s ease;width:100%}input:not([type=checkbox]):not([type=radio]):not([type=submit]):not([type=color]):not([type=button]):not([type=reset]):not(:disabled):hover,select:hover,textarea:hover,textarea[type=text]:hover{border-color:var(--color-grey)}input:not([type=checkbox]):not([type=radio]):not([type=submit]):not([type=color]):not([type=button]):not([type=reset]):focus,select:focus,textarea:focus,textarea[type=text]:focus{border-color:var(--color-primary);-webkit-box-shadow:0 0 1px var(--color-primary);box-shadow:0 0 1px var(--color-primary);outline:none}input.error:not([type=checkbox]):not([type=radio]):not([type=submit]):not([type=color]):not([type=button]):not([type=reset]),textarea.error{border-color:var(--color-error)}input.success:not([type=checkbox]):not([type=radio]):not([type=submit]):not([type=color]):not([type=button]):not([type=reset]),textarea.success{border-color:var(--color-success)}select{-webkit-appearance:none;background:#f3f3f6 no-repeat 100%;background-image:url("data:image/svg+xml;utf8,<svg xmlns='http://www.w3.org/2000/svg' width='60' height='40' fill='%23555'><polygon points='0,0 60,0 30,40'/></svg>");background-origin:content-box;background-size:1ex}[type=checkbox],[type=radio]{height:1.6rem;width:1.6rem}.button,[type=button],[type=reset],[type=submit],button{background:var(--color-lightGrey);border:1px solid transparent;border-radius:4px;color:var(--color-darkGrey);cursor:pointer;display:inline-block;font-size:var(--font-size);line-height:1;padding:1rem 2.5rem;text-align:center;text-decoration:none;-webkit-transform:scale(1);transform:scale(1);-webkit-transition:opacity .2s ease;transition:opacity .2s ease}.grouped{display:-webkit-box;display:-ms-flexbox;display:flex}.grouped>:not(:last-child){margin-right:16px}.grouped.gapless>*{border-radius:0!important;margin:0 0 0 -1px!important}.grouped.gapless>:first-child{border-radius:4px 0 0 4px!important;margin:0!important}.grouped.gapless>:last-child{border-radius:0 4px 4px 0!important}.button+.button{margin-left:1rem}.button:hover,[type=button]:hover,[type=reset]:hover,[type=submit]:hover,button:hover{opacity:.8}.button:active,[type=button]:active,[type=reset]:active,[type=submit]:active,button:active{-webkit-transform:scale(.98);transform:scale(.98)}button:disabled,button:disabled:hover,input:disabled,input:disabled:hover{cursor:not-allowed;opacity:.4}.button.dark,.button.error,.button.primary,.button.secondary,.button.success,[type=submit]{background-color:#000;background-color:var(--color-primary);color:#fff;z-index:1}.button.secondary{background-color:var(--color-grey)}.button.dark{background-color:var(--color-darkGrey)}.button.error{background-color:var(--color-error)}.button.success{background-color:var(--color-success)}.button.outline{background-color:transparent;border-color:var(--color-lightGrey)}.button.outline.primary{border-color:var(--color-primary);color:var(--color-primary)}.button.outline.secondary{border-color:var(--color-grey);color:var(--color-grey)}.button.outline.dark{border-color:var(--color-darkGrey);color:var(--color-darkGrey)}.button.clear{background-color:transparent;border-color:transparent;color:var(--color-primary)}.button.icon{-webkit-box-align:center;-ms-flex-align:center;align-items:center;display:-webkit-inline-box;display:-ms-inline-flexbox;display:inline-flex}.button.icon>img{margin-left:2px}.button.icon-only{padding:1rem}::-webkit-input-placeholder{color:#bdbfc4}::-moz-placeholder{color:#bdbfc4}:-ms-input-placeholder{color:#bdbfc4}::-ms-input-placeholder{color:#bdbfc4}::placeholder{color:#bdbfc4}.nav{-webkit-box-align:stretch;-ms-flex-align:stretch;align-items:stretch;display:-webkit-box;display:-ms-flexbox;display:flex;min-height:5rem}.nav img{max-height:3rem}.nav-center,.nav-left,.nav-right,.nav>.container{display:-webkit-box;display:-ms-flexbox;display:flex}.nav-center,.nav-left,.nav-right{-webkit-box-flex:1;-ms-flex:1;flex:1}.nav-left{-webkit-box-pack:start;-ms-flex-pack:start;justify-content:flex-start}.nav-right{-webkit-box-pack:end;-ms-flex-pack:end;justify-content:flex-end}.nav-center{-webkit-box-pack:center;-ms-flex-pack:center;justify-content:center}@media screen and (max-width:480px){.nav,.nav>.container{-webkit-box-orient:vertical;-webkit-box-direction:normal;-ms-flex-direction:column;flex-direction:column}.nav-center,.nav-left,.nav-right{-webkit-box-pack:center;-ms-flex-pack:center;-ms-flex-wrap:wrap;flex-wrap:wrap;justify-content:center}}.nav .brand,.nav a{-webkit-box-align:center;-ms-flex-align:center;align-items:center;color:var(--color-darkGrey);display:-webkit-box;display:-ms-flexbox;display:flex;padding:1rem 2rem;text-decoration:none}.nav .active:not(.button),.nav [aria-current=page]:not(.button){color:#000;color:var(--color-primary)}.nav .brand{font-size:1.75em;padding-bottom:0;padding-top:0}.nav .brand img{padding-right:1rem}.nav .button{margin:auto 1rem}.card{background:var(--bg-color);border-radius:4px;-webkit-box-shadow:0 1px 3px var(--color-grey);box-shadow:0 1px 3px var(--color-grey);padding:1rem 2rem}.card p:last-child{margin:0}.card header>*{margin-bottom:1rem;margin-top:0}.tabs{display:-webkit-box;display:-ms-flexbox;display:flex}.tabs a{text-decoration:none}.tabs>.dropdown>summary,.tabs>a{-webkit-box-flex:0;border-bottom:2px solid var(--color-lightGrey);color:var(--color-darkGrey);-ms-flex:0 1 auto;flex:0 1 auto;padding:1rem 2rem;text-align:center}.tabs>a.active,.tabs>a:hover,.tabs>a[aria-current=page]{border-bottom:2px solid var(--color-darkGrey);opacity:1}.tabs>a.active,.tabs>a[aria-current=page]{border-color:var(--color-primary)}.tabs.is-full a{-webkit-box-flex:1;-ms-flex:1 1 auto;flex:1 1 auto}.tag{border:1px solid var(--color-lightGrey);color:var(--color-grey);display:inline-block;letter-spacing:.5px;line-height:1;padding:.5rem;text-transform:uppercase}.tag.is-small{font-size:.75em;padding:.4rem}.tag.is-large{font-size:1.125em;padding:.7rem}.tag+.tag{margin-left:1rem}details.dropdown{display:inline-block;position:relative}details.dropdown>:last-child{left:0;position:absolute;white-space:nowrap}.bg-primary{background-color:var(--color-primary)!important}.bg-light{background-color:var(--color-lightGrey)!important}.bg-dark{background-color:var(--color-darkGrey)!important}.bg-grey{background-color:var(--color-grey)!important}.bg-error{background-color:var(--color-error)!important}.bg-success{background-color:var(--color-success)!important}.bd-primary{border:1px solid var(--color-primary)!important}.bd-light{border:1px solid var(--color-lightGrey)!important}.bd-dark{border:1px solid var(--color-darkGrey)!important}.bd-grey{border:1px solid var(--color-grey)!important}.bd-error{border:1px solid var(--color-error)!important}.bd-success{border:1px solid var(--color-success)!important}.text-primary{color:var(--color-primary)!important}.text-light{color:var(--color-lightGrey)!important}.text-dark{color:var(--color-darkGrey)!important}.text-grey{color:var(--color-grey)!important}.text-error{color:var(--color-error)!important}.text-success{color:var(--color-success)!important}.text-white{color:#fff!important}.pull-right{float:right!important}.pull-left{float:left!important}.text-center{text-align:center}.text-left{text-align:left}.text-right{text-align:right}.text-justify{text-align:justify}.text-uppercase{text-transform:uppercase}.text-lowercase{text-transform:lowercase}.text-capitalize{text-transform:capitalize}.is-full-screen{min-height:100vh;width:100%}.is-full-width{width:100%!important}.is-vertical-align{-webkit-box-align:center;-ms-flex-align:center;align-items:center;display:-webkit-box;display:-ms-flexbox;display:flex}.is-center,.is-horizontal-align{-webkit-box-pack:center;-ms-flex-pack:center;display:-webkit-box;display:-ms-flexbox;display:flex;justify-content:center}.is-center{-webkit-box-align:center;-ms-flex-align:center;align-items:center}.is-right{-webkit-box-pack:end;-ms-flex-pack:end;justify-content:flex-end}.is-left,.is-right{-webkit-box-align:center;-ms-flex-align:center;align-items:center;display:-webkit-box;display:-ms-flexbox;display:flex}.is-left{-webkit-box-pack:start;-ms-flex-pack:start;justify-content:flex-start}.is-fixed{position:fixed;width:100%}.is-paddingless{padding:0!important}.is-marginless{margin:0!important}.is-pointer{cursor:pointer!important}.is-rounded{border-radius:100%}.clearfix{clear:both;content:"";display:table}.is-hidden{display:none!important}@media screen and (max-width:599px){.hide-xs{display:none!important}}@media screen and (min-width:600px) and (max-width:899px){.hide-sm{display:none!important}}@media screen and (min-width:900px) and (max-width:1199px){.hide-md{display:none!important}}@media screen and (min-width:1200px){.hide-lg{display:none!important}}@media print{.hide-pr{display:none!important}}
    </style>
</head>
<body>
    <div class="container">
        <div class="row is-center">
            <h1 class="col-2 pull-left is-left">DMXAdapter</h1>
            <span class="col"></span>
            <span class="col-2 pull-right is-right" id="espMAC"> MAC address: %MACADDRESS% </span>
        </div>
        <form>
            <div class="row is-center">
                <label class="col-2 is-right" for="mode"><h4>Operating mode</h4></label>
                <select aria-label="Operating Mode" id="mode" name="mode" class="col is-center" oninput="changeMode()" required>
                    <option disabled>Choose an operation mode</option>
                    <option value="0">ESPNow</option>
                    <option value="1" disabled>MQTT</option>
                    <option value="2">ArtNet</option>
                </select>
            </div>
            <div id="espNow" hidden>
                <div class="row is-center">
                    <label for="espNowSSID" class="col-2 is-right"><h4>SSID</h4></label>
                    <input type="text" class="col is-center" id="espNowSSID" name="espNowSSID" placeholder="SSID for the AP" required>
                </div>

                <div class="row is-center">
                    <label for="espNowPassword" class="col-2 is-right"><h4>Password</h4></label>
                    <input type="text" class="col is-center" id="espNowPassword" name="espNowPassword" placeholder="Password for the AP" required>
                </div>
            </div>

            <div id="mqtt" hidden>
                <div class="row is-center">
                    <label for="mqttTopic" class="col-2 is-right"><h4>MQTT topic</h4></label>
                    <input type="text" class="col is-center" id="mqttTopic" name="mqttTopic" placeholder="MQTT topic" required>
                    <p class="text-secondary">The DMX values will be sent/received from the subtopics 0-512 of the topic you enter (eg. /stage/dmx/[0-512]).</p>
                </div>

                <div class="row is-center">
                    <label for="mqttServer" class="col-2 is-right"><h4>MQTT server</h4></label>
                    <input type="text" class="col is-center" id="mqttServer" name="mqttServer" placeholder="IP address of the MQTT broker" required>
                </div>

                <div class="row is-center">
                    <label for="mqttServerPort" class="col-2 is-right"><h4>MQTT server port</h4></label>
                    <input type="number" class="col is-center" id="mqttServerPort" name="mqttServerPort" placeholder="Port of the MQTT broker on the server" required>
                </div>

                <div class="row is-center">
                    <label for="mqttSSID" class="col-2 is-right"><h4>SSID</h4></label>
                    <input type="text" class="col is-center" id="mqttSSID" name="mqttSSID" placeholder="SSID for the WiFi you want to join" required>
                </div>

                <div class="row is-center">
                    <label for="mqttPassword" class="col-2 is-right"><h4>Password</h4></label>
                    <input type="text" class="col is-center" id="mqttPassword" name="mqttPassword" placeholder="Password for the WiFi you want to join" required>
                </div>
            </div>

            <div id="artnet" hidden>
                <div class="row is-center">
                    <label for="universe" class="col-2 is-right"><h4>ArtNet universe</h4></label>
                    <input type="number" min="0" max="512" class="col is-center" id="universe" name="universe" placeholder="Number of the ArtNet universe" required>
                </div>

                <div class="row is-center">
                    <label for="artNettSSID" class="col-2 is-right"><h4>SSID</h4></label>
                    <input type="text" class="col is-center" id="artNetSSID" name="artNetSSID" placeholder="SSID for the WiFi you want to join" required>
                </div>

                <div class="row is-center">
                    <label for="artNetPassword" class="col-2 is-right"><h4>Password</h4></label>
                    <input type="text" class="col is-center" id="artNetPassword" name="artNetPassword" placeholder="Password for the WiFi you want to join" required>
                </div>
            </div>

            <div id="motorConfig" hidden>
                <div class="row is-center">
                    <div class="col-6 is-right">
                        <label for="openPort"><h4>Open GPIO</h4></label>
                        <input type="number" min="0" max="32" class="col-8" id="openPort" name="openPort" placeholder="GPIO pin number (0 - 32) for opening relay" required>
                    </div>
                    <div class="col-6 is-right">
                        <label for="closePort"><h4>Close GPIO</h4></label>
                        <input type="number" min="0" max="32" class="col-8" id="closePort" name="closePort" placeholder="GPIO pin number (0 - 32) for closing relay" required>
                    </div>
                </div>

                <div class="row is-center">
                    <div class="col-8 is-right">
                        <label for="totalTime"><h4>Total time (in ms)</h4></label>
                        <input type="number" min="0" class="col-9" id="totalTime" name="totalTime" placeholder="Total time for the curtain to go from 0 to 100% in milliseconds (1/1000 s)" required>
                    </div>

                    <div class="col-4 is-right">
                        <label for="tolerance"><h4>+- (Tolerance)</h4></label>
                        <input type="number" min="0" max="512" class="col-7" id="tolerance" name="tolerance" placeholder="Tolerance in ms" required>
                    </div>
                </div>

                <div class="row is-center">
                    <div class="col is-right">
                        <label for="dmxAddress"><h4>DMX address</h4></label>
                        <input type="number" min="0" max="512" class="col-10" id="dmxAddress" name="dmxAddress" placeholder="DMX address (1 - 512) to listen on" required>
                    </div>
                </div>
            </div>

            <h4 class="row is-center" id="modeMessage">Please select the operating mode first!</h4>

            <div class="row is-center">
                <button type="button" class="col-2 button primary is-left is-vertical-align" id="submit" onclick="sendForm()" disabled>Perform changes</button>
                <div class="col is-right">
                    <button type="button" class="button primary is-right is-vertical-align" onclick="controlMotor(0)">Open curtain</button>
                    <button type="button" class="button error is-right is-vertical-align" onclick="controlMotor(1)">Stop curtain</button>
                    <button type="button" class="button primary is-right is-vertical-align" onclick="controlMotor(2)">Close curtain</button>
                </div>
            </div>
            
        </form>
    </div>

    <script>
        let mode
        // let broadcastAddresses = new Map()
        let broadcastAddresses = []
        loadData()
        function changeMode(){
            mode = parseInt(document.getElementById("mode").value)
            console.log("Mode: " + mode)
            if (mode == 0){
                document.getElementById("espNow").hidden = false
                document.getElementById("mqtt").hidden = true
                document.getElementById("artnet").hidden = true
                document.getElementById("motorConfig").hidden = false
                document.getElementById("modeMessage").style.display="none"
                document.getElementById("submit").disabled = false
            } else if (mode == 1) {
                document.getElementById("espNow").hidden = true
                document.getElementById("mqtt").hidden = false
                document.getElementById("artnet").hidden = true
                document.getElementById("motorConfig").hidden = false
                document.getElementById("modeMessage").style.display="none"
                document.getElementById("submit").disabled = false
            } else if (mode == 2) {
                document.getElementById("espNow").hidden = true
                document.getElementById("mqtt").hidden = true
                document.getElementById("artnet").hidden = false
                document.getElementById("motorConfig").hidden = false
                document.getElementById("modeMessage").style.display="none"
                document.getElementById("submit").disabled = false
            } 
        }
        
        function sendForm(){
            const isMQTT = (mode == 1)
            // const ssid = (!isMQTT)? document.getElementById("espNowSSID").value : document.getElementById("mqttSSID").value
            // const password = (!isMQTT)? document.getElementById("espNowPassword").value : document.getElementById("mqttPassword").value
            let ssid;
            let password;
            switch(mode) {
                case 0: 
                    ssid = document.getElementById("espNowSSID").value
                    password = document.getElementById("espNowPassword").value
                    break;
                case 1: 
                    ssid = document.getElementById("mqttSSID").value
                    password = document.getElementById("mqttPassword").value
                    break;
                case 2: 
                    ssid = document.getElementById("artNetSSID").value
                    password = document.getElementById("artNetPassword").value
                    break;
            }

            const mqttTopic = (isMQTT)? document.getElementById("mqttTopic").value : "none"
            const mqttServer = (isMQTT)? document.getElementById("mqttServer").value : "none"
            const mqttPort = (isMQTT)? document.getElementById("mqttServerPort").value : "none"
            const openPort = document.getElementById("openPort").value
            const closePort = document.getElementById("closePort").value
            const totalTime = document.getElementById("totalTime").value
            const tolerance = document.getElementById("tolerance").value
            const dmxAddress = document.getElementById("dmxAddress").value
            const artnetUniverse = document.getElementById("universe").value
            const body = {
                mode: mode,
                ssid: ssid,
                password: password,
                mqttServer: mqttServer,
                mqttPort: mqttPort,
                mqttTopic: mqttTopic,
                openPort: openPort,
                closePort: closePort,
                totalTime: totalTime,
                tolerance: tolerance,
                dmxAddress: dmxAddress,
                artnetUniverse: artnetUniverse
            }

            const xhr = new XMLHttpRequest();
            xhr.open("PUT", window.location.origin + "/settings");
            xhr.setRequestHeader("Content-Type", "application/json");
            xhr.onload = () => {
                if (xhr.readyState === 4 && xhr.status === 201) {
                    console.log(JSON.parse(xhr.responseText));
                    console.log("Success")
                } else {
                    console.log(`Error: ${xhr.status}`);
                }
            };
            console.log(body)
            xhr.send(JSON.stringify(body))
        }

        function controlMotor(action){
            const xhr = new XMLHttpRequest();
            xhr.open("POST", window.location.origin + "/motor");
            xhr.setRequestHeader("Content-Type", "text/plain");
            xhr.onload = () => {
                if (xhr.readyState === 4 && xhr.status === 201) {
                    console.log(JSON.parse(xhr.responseText));
                    console.log("Success")
                } else {
                    console.log(`Error: ${xhr.status}`);
                }
            };
            console.log(action)
            xhr.send(action)
        }

        function loadData(){
            const xhr = new XMLHttpRequest();
            xhr.open("GET", window.location.origin + "/settings");
            xhr.send();
            xhr.responseType = "json";
            xhr.onload = () => {
                if (xhr.readyState === 4 && xhr.status === 200) {
                    const data = xhr.response;
                    console.log(data);
                    document.getElementById("espMAC").innerText = "MAC address: " + data.espMAC
                    document.getElementById("mode").value = data.mode
                    changeMode()
                    if (mode == 0){
                        document.getElementById("espNowSSID").value = data.ssid
                        document.getElementById("espNowPassword").value = data.password
                    } else if (mode == 1) {
                        document.getElementById("mqttSSID").value = data.ssid
                        document.getElementById("mqttPassword").value = data.password
                        document.getElementById("mqttTopic").value = data.mqttTopic
                        document.getElementById("mqttServer").value = data.mqttServer
                        document.getElementById("mqttServerPort").value = data.mqttServer
                    } else if (mode == 2) {
                        document.getElementById("artNetSSID").value = data.ssid
                        document.getElementById("artNetPassword").value = data.password
                        document.getElementById("universe").value = data.artnetUniverse
                    }
                    document.getElementById("openPort").value = data.openPort
                    document.getElementById("closePort").value = data.closePort
                    document.getElementById("totalTime").value = data.totalTime
                    document.getElementById("tolerance").value = data.tolerance
                    document.getElementById("dmxAddress").value = data.dmxAddress
                } else {
                    console.log(`Error: ${xhr.status}`);
                }
            };
        }
    </script>
</body>
</html>
)rawliteral";

/*
* This method is called when the server receives a request to an unknown resource.
*/
void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

/*
* This method is called when the server is started.
* It sets up the webserver with its endpoints and WiFi.
*/
void setupWebserver() {
    // WiFi
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP(getSSID(), getPassword());
    Serial.println("AP SSID: " + String(getSSID()) + " Password: " + String(getPassword()));

    // Web UI
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", index_html);
    });

    // Send current settings
    server.on("/settings", HTTP_GET, [](AsyncWebServerRequest *request) {
        StaticJsonDocument<512> doc;
        deserializeJson(doc, getJSONString());
        doc["espMAC"] = WiFi.macAddress();
        String result;
        serializeJson(doc, result);
        request->send(200, "application/json", result);
    });

    // Update settings
    server.on("/settings", HTTP_PUT, [](AsyncWebServerRequest *request) {}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
        DynamicJsonDocument bodyJSON(1024);
        deserializeJson(bodyJSON, data, len);
        String result = "";
        serializeJson(bodyJSON, result);
        Serial.println("Received settings: " + result);
        setJSON(result, true);
        request->send(200, "text/plain", "OK");
    });

    // Control motor
    server.on("/motor", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
        String action = (char*) data;
        Serial.println("Received motor action: " + action);
        int command = action.toInt();
        // Serial.println("Command: " + command);

        if (command == 0) {
            digitalWrite(getOpenPort(), HIGH);
            digitalWrite(getClosePort(), LOW);
        } else if (command == 1) {
            digitalWrite(getOpenPort(), HIGH);
            digitalWrite(getClosePort(), HIGH);
        } else if (command == 2) {
            digitalWrite(getOpenPort(), LOW);
            digitalWrite(getClosePort(), HIGH);
        }

        request->send(200, "text/plain", "OK");
    });

    // Not found
    server.onNotFound(notFound);

    // Start server
    server.begin();

    Serial.println("HTTP server started");
}