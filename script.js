document.querySelector("form").addEventListener("submit", function (e) {
  let name = document.querySelector("#name").value;
  alert(`Hello ${name}`);
  e.preventDefault();
});
