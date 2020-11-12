

import * as React from "react";

function PostPreview(Props) {
  var title = Props.title;
  var author = Props.author;
  var text = title + (" - " + author);
  return React.createElement("p", undefined, text);
}

var make = PostPreview;

export {
  make ,
  
}
/* react Not a pure module */
