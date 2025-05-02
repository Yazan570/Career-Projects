$(document).ready(function() {
    var featuredProducts = [
        { id: 1, name: "T-Shirt 1", price: "$20", image: "product1.jpg" },
        { id: 2, name: "T-Shirt 2", price: "$25", image: "product2.jpg" },
        { id: 3, name: "T-Shirt 3", price: "$30", image: "product3.jpg" }
    ];

    var featuredSection = $("#featured-products");

    

    featuredProducts.forEach(product => {
        var productItem = `
            <div class="product-item">
                <img src="${product.image}" alt="${product.name}">
                <h3>${product.name}</h3>
                <p>${product.price}</p>
                <button class="add-to-cart" data-id="${product.id}">Add to Cart</button>
            </div>
        `;
        featuredSection.append(productItem);
    });

    $(".add-to-cart").click(function() {
        var productId = $(this).data("id");
        alert("Product " + productId + " added to cart.");
    });
});


function validate(e){
    var name=document.getElementById("name").value;
    if(name==""||name==null){
        alert("fill the name");
        e.preventDefault();
    }
    var search = name.search(/[^a-zA-Z]/);
    if(search != -1){
        alert("Name should not include speical characters or numbers");
        e.preventDefault();
    }
    name=document.getElementById("password").value;
    var len=name.length;
    if(len<8){
        alert("Password should be more than 8 characters");
        e.preventDefault();
    }
    search=name.search(/[0-9]/);
    if(search==-1){
        alert("Password should include at least one number");
        e.preventDefault();
    }
    search=name.search(/[A-Z]/);
    if(search==-1){
        alert("Password should include at least one uppercase letter");
        e.preventDefault();
    }
    name=document.getElementById("email").value;
    search=name.search("hotmail.com");
    var search2=name.search("gmail.com");
    var search3=name.search("std.psut.edu.jo");
    var search4=name.search("yahoo.com");
    var search5=name.search("windowslive.com");
    if(search==-1&&search2==-1&&search3==-1&&search4==-1&&search5==-1){
        alert("Email has the wrong domain");
        e.preventDefault();
    }
    
        
}

/* function enableButton(e) {
    var button = document.getElementById('addToCart');
    var checked1 =false;
    var checked2=false;
    var radio = document.getElementsByClassName("radioColors");
    for(var i=0;i<radio.length;i++)
        if(radio[i].checked){
            checked1=true;
            break;
        }
     var radio2 = document.getElementsByClassName("radioSize");
    for(var i=0;i<radio2.length;i++)
        if(radio2[i].checked){
            checked2=true;
            break;
        }
    if (!(checked1&&checked2)) {
       alert("You must select size and color");
       e.preventDefault();
       return false;
    }
    return true;
  } */


  function checkRadioGroups() {
    const group1Checked = document.querySelector('input[name="size"]:checked');
    const group2Checked = document.querySelector('input[name="Tcolor"]:checked');
    var button=document.getElementById("addToCart");

    if (group1Checked && group2Checked) {
        // Both groups are checked, perform the action
        button.disabled=false;
    } else {
        // One or both groups are not checked
        button.disabled=true;
        alert("Please select an option from both groups.");
    }
}