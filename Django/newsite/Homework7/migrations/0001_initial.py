# Generated by Django 3.2.12 on 2022-04-19 10:44

from django.db import migrations, models
import django.utils.timezone


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='HW7',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('column1', models.CharField(default='王思正', max_length=20)),
                ('column2', models.PositiveIntegerField(default=4108056004)),
                ('pub_time', models.DateTimeField(default=django.utils.timezone.now)),
            ],
            options={
                'ordering': ('-pub_time',),
            },
        ),
    ]
