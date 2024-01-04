#include<bits/stdc++.h>

using namespace std;

// tim xau con dai nhat
void algorithm(char a[], char b[], int **l){
    for(int i = 0; i <= strlen(a); i ++) l[i][0] = 0;
    for(int j = 0; j <= strlen(b); j ++) l[0][j] = 0;
    for(int i = 1; i <= strlen(a); i++){
        for(int j = 1; j <= strlen(b); j ++){
            if(a[i-1] == b[j-1])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }

}

void xau_con( char a[], char b[], char xc[], int **l){
    int i = strlen(a), j = strlen(b), k = 0;
    while(l[i][j] != 0){
        if(a[i-1] == b[j-1]){
            xc[k] = a[i-1];
            k++;
            i--;
            j--;
        }
        else {
            if ( l[i-1][j] > l[i][j-1]) i--;
            else j--;

        }
    }
    xc[k] = '\0';
    reverse(xc, xc+k);
}
int main(){
    int **l = new int*[1000];
    for(int i = 0; i<1000; i++)
           l[i] = new int[1000];
    char xc[1000] = "";
    char a[] = "BACDB";
    char b[] = "BDCB";
    algorithm(a, b, l);
    xau_con(a,b, xc, l);
    for(int i = 0; i < strlen(b); i++){
        for(int j = 0; j < strlen(a); j++){
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Longest Common Subsequence: " << xc << endl;
    return 0;
}


train_datagen = ImageDataGenerator(rescale=1./255,
                                  rotation_range=40,
                                   width_shift_range=0.2,
                                   height_shift_range=0.2,
                                   shear_range=0.2,
                                   zoom_range=0.2,
                                   horizontal_flip=True,
                                   fill_mode='nearest'
                                   )
val_datagen = ImageDataGenerator(rescale=1./255)
test_datagen = ImageDataGenerator(rescale=1./255)

train_generator = train_datagen.flow_from_directory(
    train_dir,
    target_size=(224, 224),
    batch_size=20,
    class_mode='binary'
)

test_generator = test_datagen.flow_from_directory(
    test_dir,
    target_size=(224, 224),
    batch_size=20,
    class_mode='binary'
)

val_generator = val_datagen.flow_from_directory(
    val_dir,
    target_size=(224, 224),
    batch_size=4,
    class_mode='binary'
)

def create_model(input_shape , num_class):
  model = Sequential();
  model.add(Conv2D(32, (3, 3), activation='relu', input_shape= input_shape))
  model.add(MaxPooling2D((2, 2)))
  model.add(Conv2D(64, (3, 3), activation='relu'))
  model.add(MaxPooling2D((2, 2)))
  model.add(Conv2D(128, (3, 3), activation='relu'))
  model.add(MaxPooling2D((2, 2)))
  model.add(Conv2D(128, (3, 3), activation='relu'))
  model.add(MaxPooling2D((2, 2)))
  model.add(Flatten())
  model.add(Dropout(0.2))
  model.add(Dense(512, activation='relu'))
  model.add(Dense(num_class, activation='softmax'))

  return model

input_shape = (224, 224, 2)
num_class = 2

model = create_model(input_shape, num_class)
model.summary()

model.compile(optimizer='adam',
              loss = tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])
history = model.fit_generator(train_generator,
                              steps_per_epoch=30,
                              epochs=100,
                              validation_data=val_generator,
                              validation_steps=4
                              )