// JavaScript File
// Calculating functions for price result.

var productprice;
var productlength;
var productwidth;
var productweight;
var productheight;


var cardfee = 0.0018;
var foreignfee = 0.01;
var exrate = 1209.3;
var govexrate= 1215;
var customrate = 0.08;
var taxrate = 0.1;

var carrierCode = '몰테일';



// Price Array Table for Shipping companies

var wjswlsgur;
var malltailstandard = [];
for (wjswlsgur = 0 ; wjswlsgur < 60 ; wjswlsgur++ ){
    malltailstandard[wjswlsgur] = 9 + 2*wjswlsgur;
}

var ehanexstandard = [];
ehanexstandard[0] = 9.5;
ehanexstandard[1] = 12;
ehanexstandard[2] = 14;
ehanexstandard[3] = 15.5;
ehanexstandard[4] = 17.5;
for(wjswlsgur = 5; wjswlsgur <1000; wjswlsgur++){
    ehanexstandard[wjswlsgur] = 11.5 + 1.5*wjswlsgur;
    if(wjswlsgur>65){
        ehanexstandard[wjswlsgur] = ehanexstandard[wjswlsgur] + 12;
    }
    if(wjswlsgur>219){
        ehanexstandard[wjswlsgur]=ehanexstandard[wjswlsgur]+54;
    }
    if(wjswlsgur>659){
        ehanexstandard[wjswlsgur]=ehanexstandard[wjswlsgur]+74;
    }
}






// function when button pressed, sets cardfee variable.

function cardcompanypressed(cardid){
    switch(cardid){
        case 0 :
            cardfee = 0.0018; // shinhan
            break;
        case 1 :
            cardfee = 0.002; // lotte
            break;
        case 2 :
            cardfee = 0.0025; //kookmin
            break;
        case 3:
            cardfee = 0.002; // weiwhan
            break;
        case 4:
            cardfee = 0.002; // samsung
            break;
        case 5:
            cardfee = 0.0018; // hyundai
            break;
        case 6:
            cardfee = 0.0035; // uri
        case 7 :
            cardfee = 0.0035; // nong hyup
        case 8 :
            cardfee = 0.003; // hana
        case 9 :
            cardfee = 0.0035; // BC global
        case 10:
            cardfee = 0.005; // citicard
            
    }
}

// function when button pressed, sets foreign payment fee variable.

function foreignpressed(companyid){
    switch(companyid){
        case 0 :
            foreignfee = 0.01; // VISA
            break;
        case 1 :
            foreignfee = 0.01; // MASTER
            break;
        case 2 :
            foreignfee = 0.014; // American Express
            break;
        case 3 :
            foreignfee = 0.03; // Maestro
            break;
        case 4 :
            foreignfee = 0; // JCB, BC Global, UnionPay
    }   
}




// 1. Checkout price on e-commerce site
//INPUTS
//productprice : price of the product in dollars $$$
//exrate : exchange rate KRW - USD of bank
//cardfee : card company fee(ex : shinhan card)
//foreignfee : fee for VISA/mastercard etc.
//OUTPUT
//PriceArray[] = [Total checkout price, Seller price, Card fee]

function checkoutPrice(){
    cardfee = cardfee;
     
    //javascript style
    var totalCheckoutPrice = productprice * exrate * (1 + foreignfee) * (1 + cardfee);
    var sellerPrice = productprice * exrate;
    var cardFee = totalCheckoutPrice - sellerPrice;
    return {totalCheckoutPrice:Math.round(totalCheckoutPrice),
        sellerPrice:Math.round(sellerPrice),
        cardFee:Math.round(cardFee)};
}



// 2. Shipping price
/* INPUTS
    companyarray = The shipping company's price - weight array
    height, length, width = inches
    weight = pounds
    exrate, cardfee, foreignfee = same with function checkoutPriceArray().
    
    OUTPUTS
    PriceArray[] = [Total shipping price, Shipping company price, Card fee]
*/


function shippingPrice(){
    var usedweight;
    var volumeweight = productheight * productlength * productwidth / 166;
    if (volumeweight > productweight){
        usedweight = Math.ceil(volumeweight);
    }else{
        usedweight = Math.ceil(productweight);
    }
    
    var PriceArray = [];
    if(usedweight>61){
       PriceArray[0] = 0; // 61 pound 이상은 별도견적 대상임
       PriceArray[1] = 0;
       PriceArray[2] = 0;
    }else{
        var shippingprice =  malltailstandard[usedweight-1];
        PriceArray[0] = shippingprice * exrate * (1 + foreignfee) * (1 + cardfee);
        PriceArray[1] = shippingprice * exrate;
        PriceArray[2] = PriceArray[0]-PriceArray[1];
    }
    
    console.log('PriceArray : ' + PriceArray);
    
    return {totalShippingPrice:Math.round(PriceArray[0]),
            companyPrice:Math.round(PriceArray[1]),
            cardFee:Math.round(PriceArray[2])};
    
}

// 3. Taxes
/* INPUTS
    customrate = custom tax rate of the product
    taxrate = tax rate of the product(normally 0.1)
    checkoutprice = price of the product payed at checkout in dollars
    govexrate = government exchange rate KRW - USD
    
    OUTPUTS
    PriceArray = [Total tax, custom tax, korean tax]
*/

function taxPrice(){
    var PriceArray = [];
    if(productprice>=200){
        PriceArray[1] = productprice*govexrate*customrate;
        PriceArray[2] = (productprice*govexrate+PriceArray[1])*taxrate;
        PriceArray[0] = PriceArray[1] + PriceArray[2];
    }else{
        PriceArray[0] = 0;
        PriceArray[1] = 0;
        PriceArray[2] = 0;
    }
    
    return {totalTaxPrice:Math.round(PriceArray[0]),
            customTax : Math.round(PriceArray[1]),
            koreanTax : Math.round(PriceArray[2])};
            
}

